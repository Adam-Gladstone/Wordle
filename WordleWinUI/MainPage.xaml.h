#pragma once

#include "MainPage.g.h"

#include "MainViewModel.h"

namespace winrt::WordleWinUI::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage();

        winrt::WordleWinUI::MainViewModel ViewModel();

    private:
        WordleWinUI::MainViewModel m_mainViewModel{ nullptr };

        Windows::Foundation::IAsyncAction ReportGameResult(hstring const& text) const;

    public:
        Windows::Foundation::IAsyncAction Keyboard_Tapped(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::TappedRoutedEventArgs const& e);
    };
}

namespace winrt::WordleWinUI::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
