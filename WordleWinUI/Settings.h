#pragma once
#include "Settings.g.h"

namespace winrt::WordleWinUI::implementation
{
    struct Settings : SettingsT<Settings>
    {
        Settings() = default;

        bool LightTheme();
        void LightTheme(bool value);

        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        bool m_isLightTheme{ true };

        // Property changed notifications.
        void RaisePropertyChanged(hstring const&);
        event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}

namespace winrt::WordleWinUI::factory_implementation
{
    struct Settings : SettingsT<Settings, implementation::Settings>
    {
    };
}
