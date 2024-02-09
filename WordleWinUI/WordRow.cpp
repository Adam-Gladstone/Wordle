#include "pch.h"
#include "WordRow.h"
#include "WordRow.g.cpp"

using namespace winrt;
using namespace winrt::Windows::System;
using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;

using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Data;
using namespace Microsoft::UI::Xaml::Controls;


namespace winrt::WordleWinUI::implementation
{
    WordRow::WordRow()
    {
        m_letters = single_threaded_observable_vector<WordleWinUI::Letter>();

        m_letters.Append(make<WordleWinUI::implementation::Letter>());
        m_letters.Append(make<WordleWinUI::implementation::Letter>());
        m_letters.Append(make<WordleWinUI::implementation::Letter>());
        m_letters.Append(make<WordleWinUI::implementation::Letter>());
        m_letters.Append(make<WordleWinUI::implementation::Letter>());
    }

    IObservableVector<WordleWinUI::Letter> WordRow::Letters() const
    {
        return m_letters;
    }

    void WordRow::Letters(IObservableVector<WordleWinUI::Letter> const& value)
    {
        if (m_letters != value)
        {
            m_letters = value;
            RaisePropertyChanged(L"Letters");
        }
    }

    //
    // PropertyChanged handling
    //

    event_token WordRow::PropertyChanged(PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    
    // Unregisters property changed event handler.
    void WordRow::PropertyChanged(event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);

    }

    // Triggers property changed notification.
    void WordRow::RaisePropertyChanged(hstring const& propertyName)
    {
        m_propertyChanged(*this, PropertyChangedEventArgs(propertyName));
    }
}
