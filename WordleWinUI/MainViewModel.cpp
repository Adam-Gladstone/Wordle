#include "pch.h"
#include "MainViewModel.h"
#include "MainViewModel.g.cpp"

#include "Letter.h"

#include <vector>

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

    Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> GetKeyboardRow(std::vector<IInspectable> v)
    {
        return single_threaded_observable_vector<IInspectable>(std::move(v));
    }
}

namespace winrt::WordleWinUI::implementation
{
    MainViewModel::MainViewModel()
    {
        // Initialise the collection of rows
        m_rows = single_threaded_observable_vector<WordleWinUI::WordRow>(
            { 
                make<WordleWinUI::implementation::WordRow>(), 
                make<WordleWinUI::implementation::WordRow>(),
                make<WordleWinUI::implementation::WordRow>(),
                make<WordleWinUI::implementation::WordRow>(),
                make<WordleWinUI::implementation::WordRow>() 
            }
        );
        
        // Initialise the keyboard - box the hstring values so they are iinspectable
        m_keyboardRow1 = GetKeyboardRow({ 
            box_value(L"Q"), box_value(L"W"), box_value(L"E"), box_value(L"R"), box_value(L"T"), 
            box_value(L"Y"), box_value(L"U"), box_value(L"I"), box_value(L"O"), box_value(L"P") });

        m_keyboardRow2 = GetKeyboardRow({
            box_value(L"A"), box_value(L"S"), box_value(L"D"), box_value(L"F"), box_value(L"G"),
            box_value(L"H"), box_value(L"J"), box_value(L"K"), box_value(L"L")
            });
        m_keyboardRow3 = GetKeyboardRow({
            box_value(L"<"), box_value(L"Z"), box_value(L"X"), box_value(L"C"), box_value(L"V"),
            box_value(L"B"), box_value(L"N"), box_value(L"M"), box_value(L">")
            });

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
