<a name="readme-top"></a>

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/Adam-Gladstone/Wordle">
    <img src="Images/logo.png" alt="logo" width="80" height="80">
  </a>

  <h3 align="center">Wordle</h3>

  <p align="center">
    <br />
    <a href="https://github.com/Adam-Gladstone/Wordle"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/Adam-Gladstone/Wordle/issues">Report Bug</a>
    ·
    <a href="https://github.com/Adam-Gladstone/Wordle/issues">Request Feature</a>
  </p>
</div>

<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>

<!-- ABOUT THE PROJECT -->
## About The Project
This project started out as a simple console based clone of the [Wordle](https://en.wikipedia.org/wiki/Wordle) game. The console application has no graphics, just keyboard input and the console window to output the result of each guess. It is written in C++20 and I used it as a test bed for some of the C++20 features. I was particularly interested in creating a `constexpr` game. This mostly worked except for the random number generation.

I then decided that it might be nice to add a UI to the project. So, I refactored the original console project into a static library __WordleLib__, the console application __WordleConsole__ and a test harness __WordleTest__:
* __WordleLib__: contains the core game functionality (i.e. checking the user's guess in terms of the letters and their positions) and the collection of words.
* __WordleConsole__: contains the main game loop.
* __WordleTest__: contains unit tests for the game functions. It is based on GTest and provides a simple way to check the API.

Finally, on top of __WordleLib__, I built a __WordleWinUI__ project. This is a Windows Desktop application written in C++/WinRT.
It consists of a single page which displays a board of tiles and a keyboard for selecting letters.

This project demonstrates:
* XAML:
  * Using the ItemsRepeater to display the keyboard rows and keys.
  * Using a nested DataTemplate with an ItemsRepeater to display the grid.
  * Using DataTemplate's to simplify applying styles to controls.

* MVVM
  * The `MainPage` code behind handles the construction of the view model and the keyboard 'tapped' event.
  * Separation of the `MainPage` (the view) from the model (`Letters`, `WordRow`) using the model view (`MainViewModel`) as the intermediary.
  * The `MainViewModel` handles initialising the game and processing the game turns. The underlying __WordleLib__ handles the selection of the target word, retrieving results and checking if the game is won/lost.

* C++/WinRT:
  * Resizing the main application window; setting an application icon.
  * Using Package.appxmanifest to generate icons for the taskbar.
  * Defining models using MIDL3.0, and providing implementations and type conversions.
  * `ContentDialog` and a custom MessageBox (this is still a work in progress).
  * Support for Light/Dark mode via a toggle button on the `MainPage`.
  * Support for persisting and retrieving the `LightTheme` setting from local application settings.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

* Visual Studio 2022
* C++20
* C++/WinRT
* WinUI 3.0

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

The project can be downloaded from the GitHub repository in the usual way.

### Prerequisites


### Installation


<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage
### __WordleConsole__
The console application (and the static WordleLib) is small: only ~200 lines of code. It has a small set of possible words (463). The game begins by the code choosing one word at random (see below). The user then proceeds to make guesses (up to a maximum of 5) using the report from each word to refine his/her guess. The 'report' basically says, for each letter whether the letter is correct in the position (Green), correct but not in that position (Orange) and incorrect (Grey). There are only two outcomes: you guess the word (in up to 5 guesses) or you lose.

The console application allows you to play the game. 

![Product Name Screen Shot][product-screenshot]

Of course, there is a 'cheat' mode that allows you to display the target word.

### __WordleWinUI__
The intention of __WordleWinUI__ was to use both WinUI 3.0 and XAML for the UI, but more importantly to write a Windows Desktop application in C++/WinRT. A more natural choice may have been to use C# (and I'm certain the development would have been easier). However, the underlying __WordleLib__ is written in C++20 and I did not want to wrap this with a Windows Runtime Component in order to use C# (as I have done in the past in the [Software Interoperability project](https://github.com/Adam-Gladstone/SoftwareInteroperability)).

The screenshots below show a couple of typical game turns.

![WordleWinUI](Images/WordleWinUI%20Game1.png)

![WordleWinUI](Images/WordleWinUI%20Game2.png)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/Adam-Gladstone/Wordle/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- LICENSE -->
## License

Distributed under the GPL-3.0 License. See `LICENSE.md` for more information.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- CONTACT -->
## Contact

Adam Gladstone - (https://www.linkedin.com/in/adam-gladstone-b6458b156/)

Project Link: [https://github.com/Adam-Gladstone/Wordle](https://github.com/Adam-Gladstone/Wordle)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments

Helpful resources

* [Choose an Open Source License](https://choosealicense.com)
* [Img Shields](https://shields.io)
* [GitHub Pages](https://pages.github.com)
* [Font Awesome](https://fontawesome.com)
* [React Icons](https://react-icons.github.io/react-icons/search)

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- PROJECT SHIELDS -->

[![Issues][issues-shield]][issues-url]
[![GPL-3 License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->

[issues-shield]: https://img.shields.io/github/issues/Adam-Gladstone/Wordle.svg?style=for-the-badge
[issues-url]: https://github.com/Adam-Gladstone/Wordle/issues

[license-shield]: https://img.shields.io/github/license/Adam-Gladstone/Wordle.svg?style=for-the-badge
[license-url]: https://github.com/Adam-Gladstone/Wordle/LICENSE.md

[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/adam-gladstone-b6458b156/

[product-screenshot]: Images/Screenshot.PNG
