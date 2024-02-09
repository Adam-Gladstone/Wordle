#include "pch.h"
#include "Letter.h"
#include "Letter.g.cpp"

using namespace winrt;

using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Data;
using namespace Microsoft::UI::Xaml::Media;

namespace winrt::WordleWinUI::implementation
{
    hstring Letter::Input() const
    {
        return m_input;
    }

    void Letter::Input(hstring const& value)
    {
        if (m_input != value)
        {
            m_input = value;
            RaisePropertyChanged(L"Input");
        }
    }

    Brush Letter::ColorBrush() const
    {
        return m_brush;
    }

    void Letter::ColorBrush(Brush const& value)
    {
        if (m_brush != value)
        {
            m_brush = value.as<SolidColorBrush>();
            RaisePropertyChanged(L"ColorBrush");
        }
    }

    //
    // PropertyChanged handling
    //


    event_token Letter::PropertyChanged(PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    
    // Unregisters property changed event handler.
    void Letter::PropertyChanged(event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }

    // Triggers property changed notification.
    void Letter::RaisePropertyChanged(hstring const& propertyName)
    {
        m_propertyChanged(*this, PropertyChangedEventArgs(propertyName));
    }
}
