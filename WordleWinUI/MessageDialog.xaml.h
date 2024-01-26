#pragma once

#include "MessageDialog.g.h"

namespace winrt::WordleWinUI::implementation
{
    struct MessageDialog : MessageDialogT<MessageDialog>
    {
        MessageDialog()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        hstring MessageText();
        void MessageText(hstring const& value);

    private:
        hstring m_messageText;
    };
}

namespace winrt::WordleWinUI::factory_implementation
{
    struct MessageDialog : MessageDialogT<MessageDialog, implementation::MessageDialog>
    {
    };
}
