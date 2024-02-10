#pragma once

#include "MainPage.g.h"

#include "Settings.h"
#include "MainViewModel.h"

namespace winrt::WordleWinUI::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        winrt::WordleWinUI::MainViewModel ViewModel();

        winrt::WordleWinUI::Settings ApplicationSettings();

    private:
        Windows::Storage::ApplicationDataContainer localSettings = Windows::Storage::ApplicationData::Current().LocalSettings();

        WordleWinUI::MainViewModel m_mainViewModel{ nullptr };

        WordleWinUI::Settings m_settings{ nullptr };

        Windows::Foundation::IAsyncAction ReportGameResult(hstring const& text) const;

        void ApplyTheme();

    public:
        Windows::Foundation::IAsyncAction Keyboard_Tapped(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::TappedRoutedEventArgs const& e);
        void ToggleButton_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e);
    };
}

namespace winrt::WordleWinUI::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
