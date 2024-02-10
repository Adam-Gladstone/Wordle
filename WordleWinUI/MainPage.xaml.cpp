#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif

#include <string>
#include <algorithm>

#include "App.xaml.h"
#include "MessageBox.xaml.h"

using namespace winrt;
using namespace winrt::Windows::System;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Storage;

using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Input;

namespace winrt::WordleWinUI::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();

        m_mainViewModel = make<WordleWinUI::implementation::MainViewModel>();

        m_settings = make<WordleWinUI::implementation::Settings>();

        bool hasSetting = localSettings ? localSettings.Values().HasKey(L"LightTheme") : false;
        bool isLightTheme = hasSetting ? localSettings.Values().Lookup(L"LightTheme").as<bool>() : true;
        m_settings.LightTheme(isLightTheme);

        ApplyTheme();
    }

    WordleWinUI::MainViewModel MainPage::ViewModel()
    {
        return m_mainViewModel;
    }

    WordleWinUI::Settings MainPage::ApplicationSettings()
    {
        return m_settings;
    }

    IAsyncAction MainPage::Keyboard_Tapped(IInspectable const& sender, TappedRoutedEventArgs const&)
    {
        auto textBlock = sender.as<TextBlock>();

        auto text = textBlock.Text();

        WordleWinUI::GameStatus status = m_mainViewModel.EnterLetter(text);

        if (status == WordleWinUI::GameStatus::Win)
        {
            return ReportGameResult(L"You win.\nDo you want to play again?");
        }
        else if (status == WordleWinUI::GameStatus::Lose)
        {
            return ReportGameResult(L"Game Over! You are out of turns.\nDo you want to play again?");
        }
        else
        {
            return {};
        }
    }

    IAsyncAction MainPage::ReportGameResult(hstring const& text) const
    {
        hstring title = App::Window().Title();

        auto result = co_await WordleWinUI::ModalView::MessageDialogAsync(
            *this,
            title,
            text,
            WordleWinUI::MessageBoxButtonType::YesNo,
            WordleWinUI::MessageBoxIconType::Question);

        if (result == ContentDialogResult::Primary)
        {
            CPP_TRACE("MessageBox was closed with the primary button.\n");

            m_mainViewModel.InitialiseGame();
        }
        else
        {
            CPP_TRACE("MessageBox was cancelled.\n");
        }
    }

    void MainPage::ToggleButton_Click(IInspectable const& sender, RoutedEventArgs const& e)
    {
        auto settings = ApplicationSettings();

        settings.LightTheme(!settings.LightTheme());

        localSettings.Values().Insert(L"LightTheme", box_value(settings.LightTheme()));

        ApplyTheme();
    }

    void MainPage::ApplyTheme()
    {
        auto settings = ApplicationSettings();

        Microsoft::UI::Xaml::FrameworkElement const& element = (*this);

        element.RequestedTheme(settings.LightTheme() ? ElementTheme::Light : ElementTheme::Dark);
    }
}
