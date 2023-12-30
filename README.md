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
One day when I was bored, I decided to write a simple version of the popular Wordle game. This is it - a basic console application. It has no graphics, just keyboard input and the console window to output the result of each guess.

It is written in C++20 and I use it as a test bed for some of the C++20 features. One of the main questions I had when writing it was: is it possible to have a fully 'constexpr' game?

The original solution consisted of a single console application. I have since refactored this and the solution now consists of three projects:
* WordleLib: contains the core game functionality (i.e. checking the user's guess in terms of the letters and their positions) and the collection of words.
* WordleConsole: contains the main game loop.
* WordleTest: contains unit tests for the game functions.

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Built With

* Visual Studio 2022
* C++20

<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

The project can be downloaded from the GitHub repository in the usual way.

### Prerequisites


### Installation


<p align="right">(<a href="#readme-top">back to top</a>)</p>

<!-- USAGE EXAMPLES -->
## Usage
The entire game is only ~200 lines of code. It has a small set of possible words (463). The game begins by the code choosing one word at random (see below). The user then proceeds to make guesses (up to a maximum of 5) using the report from each word to refine his/her guess. The 'report' basically says, for each letter whether the letter is correct in the position (Green), correct but not in that position (Orange) and incorrect (Grey). There are only two outcomes: you guess the word (in up to 5 guesses) or you lose.

The console application allows you to play the game. 

![Product Name Screen Shot][product-screenshot]

Of course, there is a 'cheat' mode that allows you to display the target word.

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
