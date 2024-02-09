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

using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls;
using namespace Microsoft::UI::Xaml::Input;

namespace winrt::WordleWinUI::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();

        m_mainViewModel = make<WordleWinUI::implementation::MainViewModel>();
    }

    winrt::WordleWinUI::MainViewModel MainPage::ViewModel()
    {
        return m_mainViewModel;
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
}

