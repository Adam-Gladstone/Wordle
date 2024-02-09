#include "pch.h"
#include "ModalView.h"
#include "ModalView.g.cpp"

#include "MessageBox.xaml.h"

using namespace winrt;
using namespace winrt::Windows::System;
using namespace winrt::Windows::Foundation;

using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Data;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::WordleWinUI::implementation
{
    IAsyncOperation<ContentDialogResult> 
        ModalView::MessageDialogAsync(
            FrameworkElement const& element,
            hstring const& title,
            hstring const& message)
    {
        auto result = co_await MessageDialogAsync(
            element, 
            title, 
            message, 
            WordleWinUI::MessageBoxButtonType::OK, 
            WordleWinUI::MessageBoxIconType::Information
        );
        co_return result;
    }

    IAsyncOperation<ContentDialogResult>
        ModalView::MessageDialogAsync(
            FrameworkElement const& element,
            hstring const& title,
            hstring const& message,
            WordleWinUI::MessageBoxButtonType buttons, 
            WordleWinUI::MessageBoxIconType icon)
    {
        ContentDialog dialog{};

        auto content = make<WordleWinUI::implementation::MessageBox>();
        content.ImageSource(GetImageSource(icon));
        content.MessageText(message);

        dialog.XamlRoot(element.XamlRoot());
        dialog.Title(box_value(title));
        dialog.Content(content);

        SetDialogButtons(dialog, buttons);

        auto result = co_await dialog.ShowAsync();

        co_return result;
    }

    hstring ModalView::GetImageSource(WordleWinUI::MessageBoxIconType icon)
    {
        hstring source{ L"/Assets/" };

        switch (icon)
        {
        case MessageBoxIconType::Hand:
            return source + hstring(L"hand.png");
        case MessageBoxIconType::Error:
            return source + hstring(L"error.png");
        case MessageBoxIconType::Stop:
            return source + hstring(L"stop.png");
        case MessageBoxIconType::Question:
            return source + hstring(L"question.png");
        case MessageBoxIconType::Exclamation:
            return source + hstring(L"exclamation.png");
        case MessageBoxIconType::Warning:
            return source + hstring(L"warning.png");
        case MessageBoxIconType::Information:
            return source + hstring(L"information.png");
        case MessageBoxIconType::Asterisk:
            return source + hstring(L"asterisk.png");
        default:
            return hstring(L"");
        }
    }

    void ModalView::SetDialogButtons(
        ContentDialog& dialog, 
        WordleWinUI::MessageBoxButtonType buttons)
    {
        if (buttons == MessageBoxButtonType::OK)
        {
            dialog.PrimaryButtonText(L"OK");
        }
        else if (buttons == MessageBoxButtonType::OKCancel)
        {
            dialog.PrimaryButtonText(L"OK");
            dialog.SecondaryButtonText(L"Cancel");
        }
        else if (buttons == MessageBoxButtonType::RetryCancel)
        {
            dialog.PrimaryButtonText(L"Retry");
            dialog.SecondaryButtonText(L"Cancel");
        }
        else if (buttons == MessageBoxButtonType::YesNo)
        {
            dialog.PrimaryButtonText(L"Yes");
            dialog.SecondaryButtonText(L"No");
        }
        else if (buttons == MessageBoxButtonType::YesNoCancel)
        {
            dialog.PrimaryButtonText(L"Yes");
            dialog.SecondaryButtonText(L"No");
            dialog.CloseButtonText(L"Cancel");
        }
        else if (buttons == MessageBoxButtonType::AbortRetryIgnore)
        {
            dialog.PrimaryButtonText(L"Abort");
            dialog.SecondaryButtonText(L"Retry");
            dialog.CloseButtonText(L"Ignore");
        }
        else
        {
            dialog.PrimaryButtonText(L"OK");
        }

        dialog.DefaultButton(ContentDialogButton::Primary);
    }

    //
    // PropertyChanged handling
    //
    event_token ModalView::PropertyChanged(PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }

    // Unregisters property changed event handler.
    void ModalView::PropertyChanged(event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }

    // Triggers property changed notification.
    void ModalView::RaisePropertyChanged(hstring const& propertyName)
    {
        m_propertyChanged(*this, PropertyChangedEventArgs(propertyName));
    }
}
