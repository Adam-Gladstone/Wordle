#include "pch.h"
#include "MessageDialog.xaml.h"
#if __has_include("MessageDialog.g.cpp")
#include "MessageDialog.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::WordleWinUI::implementation
{
    hstring MessageDialog::MessageText()
    {
        return m_messageText;
    }
    void MessageDialog::MessageText(hstring const& value)
    {
        m_messageText = value;
    }
}
