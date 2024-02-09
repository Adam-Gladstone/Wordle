#pragma once
#include "ModalView.g.h"

namespace winrt::WordleWinUI::implementation
{
    struct ModalView : ModalViewT<ModalView>
    {
        ModalView() = default;

        static winrt::Windows::Foundation::IAsyncOperation<winrt::Microsoft::UI::Xaml::Controls::ContentDialogResult>
            MessageDialogAsync(
                winrt::Microsoft::UI::Xaml::FrameworkElement const& element, 
                winrt::hstring const& title, 
                winrt::hstring const& message
            );

        static winrt::Windows::Foundation::IAsyncOperation<winrt::Microsoft::UI::Xaml::Controls::ContentDialogResult>
            MessageDialogAsync(
                winrt::Microsoft::UI::Xaml::FrameworkElement const& element, 
                winrt::hstring const& title, 
                winrt::hstring const& message, 
                WordleWinUI::MessageBoxButtonType buttons, 
                WordleWinUI::MessageBoxIconType icon
            );

        // Event handling
        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        static hstring GetImageSource(WordleWinUI::MessageBoxIconType icon);
        static void SetDialogButtons(
            winrt::Microsoft::UI::Xaml::Controls::ContentDialog& dialog, 
            WordleWinUI::MessageBoxButtonType buttons
        );

        // Property changed notifications.
        void RaisePropertyChanged(winrt::hstring const&);
        winrt::event<winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::WordleWinUI::factory_implementation
{
    struct ModalView : ModalViewT<ModalView, implementation::ModalView>
    {
    };
}
