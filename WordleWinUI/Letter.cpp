#include "pch.h"
#include "Letter.h"
#include "Letter.g.cpp"

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

    Microsoft::UI::Xaml::Media::Brush Letter::ColorBrush() const
    {
        return m_brush;
    }

    void Letter::ColorBrush(Microsoft::UI::Xaml::Media::Brush const& value)
    {
        if (m_brush != value)
        {
            m_brush = value.as<Microsoft::UI::Xaml::Media::SolidColorBrush>();
            RaisePropertyChanged(L"ColorBrush");
        }
    }

    //
    // PropertyChanged handling
    //


    winrt::event_token Letter::PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler)
    {
        return m_propertyChanged.add(handler);
    }
    
    // Unregisters property changed event handler.
    void Letter::PropertyChanged(winrt::event_token const& token) noexcept
    {
        m_propertyChanged.remove(token);
    }

    // Triggers property changed notification.
    void Letter::RaisePropertyChanged(hstring const& propertyName)
    {
        m_propertyChanged(*this, Microsoft::UI::Xaml::Data::PropertyChangedEventArgs(propertyName));
    }
}
