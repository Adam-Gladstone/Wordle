#include "pch.h"
#include "MainPage.xaml.h"
#if __has_include("MainPage.g.cpp")
#include "MainPage.g.cpp"
#endif

#include <string>
#include <algorithm>

#include "MessageDialog.xaml.h"

using namespace winrt;
using namespace winrt::Windows::System;
using namespace Microsoft::UI::Xaml;

namespace winrt::WordleWinUI::implementation
{
    MainPage::MainPage()
    {
        InitializeComponent();

        m_mainViewModel = winrt::make<WordleWinUI::implementation::MainViewModel>();
    }

    winrt::WordleWinUI::MainViewModel MainPage::ViewModel()
    {
        return m_mainViewModel;
    }

    void MainPage::Keyboard_Tapped(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::TappedRoutedEventArgs const&)
    {
        auto textBlock = sender.as<::winrt::Microsoft::UI::Xaml::Controls::TextBlock>();

        auto text = textBlock.Text();

        winrt::WordleWinUI::GameStatus status = m_mainViewModel.EnterLetter(text);

        if (status == winrt::WordleWinUI::GameStatus::Win)
        {
            ReportGameResult(L"Genius. You win.");
        }
        else if (status == winrt::WordleWinUI::GameStatus::Lose)
        {
            ReportGameResult(L"Game Over! You are out of turns.");
        }
    }

    void MainPage::ReportGameResult(hstring const& text) const
    {
        winrt::Microsoft::UI::Xaml::Controls::ContentDialog dialog{};

        auto inner = winrt::make<WordleWinUI::implementation::MessageDialog>();
        inner.MessageText(text);

        dialog.XamlRoot(this->XamlRoot());
        dialog.Title(box_value(L"Game Result"));
        dialog.Content(box_value(text));
        //dialog.Content(inner);
        dialog.PrimaryButtonText(L"Ok");
        dialog.IsPrimaryButtonEnabled(true);
        dialog.PrimaryButtonClick(
            [&](auto&& ...)
            {
                m_mainViewModel.InitialiseGame();
            }
        );

        dialog.ShowAsync().Completed([&](auto&& ...) {});

        /*
        winrt::Windows::Foundation::IAsyncOperation<winrt::Microsoft::UI::Xaml::Controls::ContentDialogResult> result
            = dialog.ShowAsync();
        if (result.GetResults() == winrt::Microsoft::UI::Xaml::Controls::ContentDialogResult::Primary)
        {
            m_mainViewModel.InitialiseGame();
        }
        */
    }
}

