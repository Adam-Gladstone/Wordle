#include "pch.h"
#include "WordRow.h"
#include "WordRow.g.cpp"

namespace winrt::WordleWinUI::implementation
{
    WordRow::WordRow()
    {
        m_letters = winrt::single_threaded_observable_vector<WordleWinUI::Letter>();

        m_letters.Append(winrt::make<WordleWinUI::implementation::Letter>());
        m_letters.Append(winrt::make<WordleWinUI::implementation::Letter>());
        m_letters.Append(winrt::make<WordleWinUI::implementation::Letter>());
        m_letters.Append(winrt::make<WordleWinUI::implementation::Letter>());
        m_letters.Append(winrt::make<WordleWinUI::implementation::Letter>());
    }

    Windows::Foundation::Collections::IObservableVector<WordleWinUI::Letter> WordRow::Letters() const
    {
        return m_letters;
    }

    void WordRow::Letters(Windows::Foundation::Collections::IObservableVector<WordleWinUI::Letter> const& value)
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

    winrt::event_token WordRow::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    
    // Unregisters property changed event handler.
    void WordRow::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);

    }

    // Triggers property changed notification.
    void WordRow::RaisePropertyChanged(hstring const& propertyName)
    {
        m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs(propertyName));
    }
}
