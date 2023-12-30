// WordleLib.cpp
//

#include <random>

#include "WordleLib.h"

namespace wordle
{
    // Generate an index value between 0 and max - 1
    /*constexpr*/ auto get_index([[maybe_unused]] std::size_t max) -> std::size_t
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distribution{ 0, static_cast<std::int32_t>(max - 1) };
        return distribution(gen);
    }

    // Evaluate one character at the specified position of the user's guess
    auto evaluate(char input_ch, std::size_t position, std::string_view target_word) -> result
    {
        result retval{ result::grey };
        const std::size_t size = target_word.size();
        for (std::size_t i = 0; i < size; ++i)
        {
            if (target_word.at(i) == input_ch)
            {
                if(retval != result::green)
                    retval = result::orange;

                if (position == i)
                {
                    retval = result::green;
                }
            }
        }
        return retval;
    }

    // Report the result (grey, orange, green) for each character position in the user's guess
    auto report(std::string_view input_word, std::string_view target_word) -> std::array<result, length>
    {
        std::array<result, length> report{};

        const std::size_t size = target_word.size();
        for (std::size_t i = 0; i < size; ++i)
        {
            const auto input_ch = input_word.at(i);

            report[i] = evaluate(input_ch, i, target_word);
        }

        return report;
    }

    // Determine if the result is green in all positions
    auto is_win(const std::array<result, length>& results) -> bool
    {
        bool win = true;
        for (const auto& result : results)
        {
            if (result != result::green)
            {
                win = false;
            }
        }
        return win;
    }
}
