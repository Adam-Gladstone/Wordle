#pragma once
#include "Letter.g.h"

namespace winrt::WordleWinUI::implementation
{
    struct Letter : LetterT<Letter>
    {
        Letter() = default;

        hstring Input() const;
        void Input(hstring const& value);

        Microsoft::UI::Xaml::Media::Brush ColorBrush() const;
        void ColorBrush(Microsoft::UI::Xaml::Media::Brush const& value);

        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        hstring m_input{};
        Microsoft::UI::Xaml::Media::SolidColorBrush m_brush;

        // Property changed notifications.
        void RaisePropertyChanged(hstring const&);
        event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::WordleWinUI::factory_implementation
{
    struct Letter : LetterT<Letter, implementation::Letter>
    {
    };
}
