#include "pch.h"
#include "MessageBox.xaml.h"
#if __has_include("MessageBox.g.cpp")
#include "MessageBox.g.cpp"
#endif

using namespace winrt;

namespace winrt::WordleWinUI::implementation
{
    hstring MessageBox::MessageText()
    {
        return m_messageText;
    }
    void MessageBox::MessageText(hstring const& value)
    {
        m_messageText = value;
    }

    hstring MessageBox::ImageSource()
    {
        return m_imageSource;
    }
    void MessageBox::ImageSource(hstring const& value)
    {
        m_imageSource = value;
    }
}
