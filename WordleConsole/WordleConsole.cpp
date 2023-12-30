//
// WordleConsole.cpp
//

#include <iostream>

#include "WordleLib.h"

using namespace std::literals;

namespace {

    auto get_word(std::string_view prompt, std::size_t guess) -> std::string
    {
        std::cout << prompt << "(" << guess << ") > ";
        std::string name;
        std::getline(std::cin, name);
        return name;
    }

    void display(const std::array<wordle::result, wordle::length>& results)
    {
        for (const auto& result : results)
        {
            std::cout << wordle::result_string(result) << '\t';
        }
        std::cout << '\n';
    }

}

auto main() -> int
{
    // Add some notion of a session to ensure target words are not repeated
    std::cout << "You have 5 attempts to deduce the word. Good luck!\n";
    const auto index = wordle::get_index(wordle::count);
    //const std::string_view target = wordle::select_word(index);
    const std::string_view target{ "extra" };
    std::cout << "Target word: " << target << '\n';

    auto win = false;
    static constexpr std::size_t num_turns = 5;
    for (std::size_t i = 0; i < num_turns; ++i)
    {
        std::string word = get_word("Guess"sv, i + 1);

        if (!wordle::is_valid(word))
        {
            std::cout << "The word (" << word << ") is not valid.\n";
        }
        else
        {
            auto results = wordle::report(word, target);
            display(results);
            win = wordle::is_win(results);
            if (win)
            {
                break;
            }
        }
    }

    if (win)
    {
        std::cout << "Congratulations. You have won!\n";
    }
    else
    {
        std::cout << "You lose. Better luck next time.\n";
    }

    return 0;
}
