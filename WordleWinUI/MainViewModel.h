#pragma once
#include "MainViewModel.g.h"

#include "Letter.h"
#include "WordRow.h"

namespace winrt::WordleWinUI::implementation
{
    struct MainViewModel : MainViewModelT<MainViewModel>
    {
        MainViewModel();

        Windows::Foundation::Collections::IObservableVector<WordleWinUI::WordRow> Rows() const;
        void Rows(Windows::Foundation::Collections::IObservableVector<WordleWinUI::WordRow> const& value);

        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> KeyboardRow1() const;
        void KeyboardRow1(Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> const& value);

        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> KeyboardRow2() const;
        void KeyboardRow2(Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> const& value);

        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> KeyboardRow3() const;
        void KeyboardRow3(Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> const& value);

        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

        winrt::WordleWinUI::GameStatus EnterLetter(const hstring& hs);

        void InitialiseGame();

    private:
        std::string m_target{};
        uint32_t m_rowIndex{};
        uint32_t m_colIndex{};

        winrt::WordleWinUI::GameStatus OnEnter();

        std::string GetGuess() const;

        Windows::Foundation::Collections::IObservableVector<WordleWinUI::WordRow> m_rows;

        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> m_keyboardRow1;
        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> m_keyboardRow2;
        Windows::Foundation::Collections::IObservableVector<Windows::Foundation::IInspectable> m_keyboardRow3;

        // Property changed notifications.
        void RaisePropertyChanged(hstring const&);
        event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;

        winrt::Windows::UI::Color GetBackgroundColor(wordle::result colour) const;
    };
}
namespace winrt::WordleWinUI::factory_implementation
{
    struct MainViewModel : MainViewModelT<MainViewModel, implementation::MainViewModel>
    {
    };
}
