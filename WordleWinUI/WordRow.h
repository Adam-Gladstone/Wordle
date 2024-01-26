#pragma once

#include "Letter.h"

#include "WordRow.g.h"

namespace winrt::WordleWinUI::implementation
{
    struct WordRow : WordRowT<WordRow>
    {
        WordRow();

        Windows::Foundation::Collections::IObservableVector<WordleWinUI::Letter> Letters() const;
        void Letters(Windows::Foundation::Collections::IObservableVector<WordleWinUI::Letter> const& value);

        winrt::event_token PropertyChanged(winrt::Microsoft::UI::Xaml::Data::PropertyChangedEventHandler const& handler);
        void PropertyChanged(winrt::event_token const& token) noexcept;

    private:
        Windows::Foundation::Collections::IObservableVector<WordleWinUI::Letter> m_letters;

        // Property changed notifications.
        void RaisePropertyChanged(hstring const&);

        event<Microsoft::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
    };
}
namespace winrt::WordleWinUI::factory_implementation
{
    struct WordRow : WordRowT<WordRow, implementation::WordRow>
    {
    };
}
