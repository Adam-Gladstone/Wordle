#pragma once

#include "MessageBox.g.h"

namespace winrt::WordleWinUI::implementation
{
    struct MessageBox : MessageBoxT<MessageBox>
    {
        MessageBox() = default;

        winrt::hstring ImageSource();
        void ImageSource(winrt::hstring const& value);

        winrt::hstring MessageText();
        void MessageText(winrt::hstring const& value);

    private:
        winrt::hstring m_messageText;
        winrt::hstring m_imageSource;
    };
}

namespace winrt::WordleWinUI::factory_implementation
{
    struct MessageBox : MessageBoxT<MessageBox, implementation::MessageBox>
    {
    };
}
