#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::WordleWinUI::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

        winrt::hstring title{ L"WordleWinUI" };
        this->Title(title);
        //
        // Requires including '#include <winrt/Microsoft.UI.Windowing.h>'
        // Otherwise you receive the error: https://devblogs.microsoft.com/oldnewthing/20190530-00/?p=102529
        //
        AppWindow().Resize({ 570, 810 });

        AppWindow().SetIcon(L"Assets\\Document.ico");
    }
}
