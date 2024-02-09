#include "pch.h"
#include "MainViewModel.h"
#include "MainViewModel.g.cpp"

#include "Letter.h"

using namespace winrt;
using namespace winrt::Windows::UI;
using namespace winrt::Windows::System;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;

using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Data;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Media;

namespace {
    constexpr std::array<std::string_view, 10> keyboardRow1{ "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P"};
    constexpr std::array<std::string_view, 9>  keyboardRow2{ "A", "S", "D", "F", "G", "H", "J", "K", "L" };
    constexpr std::array<std::string_view, 9>  keyboardRow3{ "<", "Z", "X", "C", "V", "B", "N", "M", ">" };
}

namespace winrt::WordleWinUI::implementation
{
    MainViewModel::MainViewModel()
    {
        // Initialise the collection of rows
        m_rows = single_threaded_observable_vector<WordleWinUI::WordRow>();
        m_rows.Append(make<WordleWinUI::implementation::WordRow>());
        m_rows.Append(make<WordleWinUI::implementation::WordRow>());
        m_rows.Append(make<WordleWinUI::implementation::WordRow>());
        m_rows.Append(make<WordleWinUI::implementation::WordRow>());
        m_rows.Append(make<WordleWinUI::implementation::WordRow>());

        // Initialise the keyboard
        m_keyboardRow1 = single_threaded_observable_vector<IInspectable>();
        m_keyboardRow2 = single_threaded_observable_vector<IInspectable>();
        m_keyboardRow3 = single_threaded_observable_vector<IInspectable>();

        // https://github.com/jamesmontemagno/FiveLetters/blob/master/FiveLetters/ViewModel/GameViewModel.cs
        // C#: KeyboardRow1 = "QWERTYUIOP".ToCharArray();
        for (const auto& letter : keyboardRow1)
            m_keyboardRow1.Append(box_value(to_hstring(letter)));

        for (const auto& letter : keyboardRow2)
            m_keyboardRow2.Append(box_value(to_hstring(letter)));

        for (const auto& letter : keyboardRow3)
            m_keyboardRow3.Append(box_value(to_hstring(letter)));

        InitialiseGame();
    }

    void MainViewModel::InitialiseGame()
    {
        // Acquire a target word
        const auto index = wordle::get_index(wordle::count);
        m_target = wordle::select_word(index);
        CPP_TRACE("Target is: %s\n", m_target.c_str());

        // Reset indexes
        m_rowIndex = 0;
        m_colIndex = 0;

        SolidColorBrush brush{ Colors::Transparent() };
        hstring blank{ L" " };

        // Reset letters
        for (uint32_t i = 0; i < wordle::length; ++i)
        {
            auto row = Rows().GetAt(i);
            auto letters = row.Letters();
            for (uint32_t j = 0; j < wordle::length; ++j)
            {
                auto letter = letters.GetAt(j);

                letter.Input(blank);
                letter.ColorBrush(brush);
            }
        }
    }

    IObservableVector<WordleWinUI::WordRow> MainViewModel::Rows() const
    {
        return m_rows;
    }

    void MainViewModel::Rows(IObservableVector<WordleWinUI::WordRow> const& value)
    {
        if (m_rows != value)
        {
            m_rows = value;
            RaisePropertyChanged(L"Rows");
        }
    }

    IObservableVector<IInspectable> MainViewModel::KeyboardRow1() const
    {
        return m_keyboardRow1;
    }

    void MainViewModel::KeyboardRow1(IObservableVector<IInspectable> const& value)
    {
        if (m_keyboardRow1 != value)
        {
            m_keyboardRow1 = value;
            RaisePropertyChanged(L"KeyboardRow1");
        }
    }

    IObservableVector<IInspectable> MainViewModel::KeyboardRow2() const
    {
        return m_keyboardRow2;
    }

    void MainViewModel::KeyboardRow2(IObservableVector<IInspectable> const& value)
    {
        if (m_keyboardRow2 != value)
        {
            m_keyboardRow2 = value;
            RaisePropertyChanged(L"KeyboardRow2");
        }
    }

    IObservableVector<IInspectable> MainViewModel::KeyboardRow3() const
    {
        return m_keyboardRow3;
    }

    void MainViewModel::KeyboardRow3(IObservableVector<IInspectable> const& value)
    {
        if (m_keyboardRow3 != value)
        {
            m_keyboardRow3 = value;
            RaisePropertyChanged(L"KeyboardRow3");
        }
    }

    // Registers property changed event handler.
    event_token MainViewModel::PropertyChanged(PropertyChangedEventHandler const& value)
    {
        return m_propertyChanged.add(value);
    }

    // Unregisters property changed event handler.
    void MainViewModel::PropertyChanged(event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }

    // Triggers property changed notification.
    void MainViewModel::RaisePropertyChanged(hstring const& propertyName)
    {
        m_propertyChanged(*this, PropertyChangedEventArgs(propertyName));
    }

    Color MainViewModel::GetBackgroundColor(wordle::result colour) const
    {
        if (colour == wordle::result::grey)
            return Colors::Gray();
        else if (colour == wordle::result::orange)
            return Colors::Orange();
        else if (colour == wordle::result::green)
            return Colors::Green();
        else
            return Colors::Transparent();
    }

    std::string MainViewModel::GetGuess() const
    {
        std::string s{};
        const auto& row = Rows().GetAt(m_rowIndex);
        const auto& letters = row.Letters();
        for (const auto& letter : letters)
        {
            s.append(to_string(letter.Input()));
        }

        std::transform(s.begin(), s.end(), s.begin(), 
            [](unsigned char c) 
            { 
                return static_cast<unsigned char>(std::tolower(c)); 
            }
        );
        return s;
    }

    winrt::WordleWinUI::GameStatus MainViewModel::OnEnter()
    {
        if (m_colIndex != wordle::length)
            return winrt::WordleWinUI::GameStatus::InvalidLine;

        auto row = Rows().GetAt(m_rowIndex);
        auto letters = row.Letters();

        std::string s{ GetGuess() };
        if (!wordle::is_valid(s))
        {
            SolidColorBrush brush{ Colors::PaleVioletRed() };
            for (uint32_t column = 0; column < wordle::length; ++column)
            {
                letters.GetAt(column).ColorBrush(brush);
            }
            return winrt::WordleWinUI::GameStatus::InvalidWord;
        }

        auto results = wordle::report(s, m_target);
        for (uint32_t column = 0; column < wordle::length; ++column)
        {
            SolidColorBrush brush{ GetBackgroundColor(results[column]) };
            
            letters.GetAt(column).ColorBrush(brush);
        }

        if (wordle::is_win(results))
        {
            return winrt::WordleWinUI::GameStatus::Win;
        }

        if (m_rowIndex == 4)
        {
            return winrt::WordleWinUI::GameStatus::Lose;
        }
        else
        {
            m_rowIndex++;
            m_colIndex = 0;
        }

        return winrt::WordleWinUI::GameStatus::NextTurn;
    }

    winrt::WordleWinUI::GameStatus MainViewModel::EnterLetter(const hstring& hs)
    {
        std::string s = to_string(hs);
        CPP_TRACE("EnterLetter: %s\n", s.c_str());

        if (s == ">")
        {
            return OnEnter();
        }

        if (s == "<")
        {
            if (m_colIndex == 0)
                return winrt::WordleWinUI::GameStatus::ThisTurn;

            m_colIndex--;

            SolidColorBrush brush{ Colors::Transparent() };
            hstring blank{ L" " };

            auto row = Rows().GetAt(m_rowIndex);
            auto letters = row.Letters();
            auto letter = letters.GetAt(m_colIndex);
            letter.Input(blank);
            letter.ColorBrush(brush);

            return winrt::WordleWinUI::GameStatus::ThisTurn;
        }

        if (m_colIndex == 5)
            return winrt::WordleWinUI::GameStatus::NextTurn;

        auto row = Rows().GetAt(m_rowIndex);
        auto letters = row.Letters();
        auto letter = letters.GetAt(m_colIndex);
        letter.Input(to_hstring(s));

        m_colIndex++;
        return winrt::WordleWinUI::GameStatus::NextTurn;
    }
}
