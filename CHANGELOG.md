# Issues

# Wishlist

## WordleLib
- find a way to do the random number generator in a constexpr context.
- replace the loop constructs with ranges.
- add full list of guessable words (?).

## WordleTest


## WordleWinUI
- refactor PropertyChanged handling to use a templated class
- refactor the ContentDialog + MessageDialog class


# Changes
## 27/01/2024
Initial checkin

## 09/02/2024
- Updated end of game message boxes. This now uses a more generic MessageDialogAsync call to emulate Windows message boxes
- Removed redundant namespaces.

## 10/02/2024
- Added generic settings class with a single setting for LightTheme.
- Added support for getting/setting LightTheme.
