#include "pch.h"


TEST(TestWordle, TestResultString)
{
	// Arrange
	constexpr std::string_view green = wordle::result_string(wordle::result::green);
	constexpr std::string_view grey = wordle::result_string(wordle::result::grey);
	constexpr std::string_view orange = wordle::result_string(wordle::result::orange);

	// Act

	// Assert
	EXPECT_EQ(green, std::string_view{ "Green" });
	EXPECT_EQ(grey, std::string_view{ "Grey" });
	EXPECT_EQ(orange, std::string_view{ "Orange" });
}

TEST(TestWordle, SelectWordInvalidIndex) 
{
	// Arrange
	// Act
	// Assert
	const std::size_t invalid_index = -1;

	EXPECT_THROW(
		[[maybe_unused]] std::string_view word = wordle::select_word(invalid_index),
		std::out_of_range
	);
}

TEST(TestWordle, SelectWordValidIndex)
{
	// Arrange - Act
	constexpr std::string_view first_word = wordle::select_word(0);
	constexpr std::string_view last_word = wordle::select_word(wordle::count - 1);

	std::string_view first_target{ "avoid" };
	std::string_view last_target{ "youth" };

	// Assert
	EXPECT_EQ(first_word, first_target);
	EXPECT_EQ(last_word, last_target);
}

TEST(TestWordle, TestReportNoHits)
{
	// Arrange
	std::array<wordle::result, wordle::length> no_hits
	{
		{ wordle::result::grey, wordle::result::grey, wordle::result::grey, wordle::result::grey, wordle::result::grey }
	};

	// Act
	auto target = wordle::report("about", "wheel");

	// Assert
	EXPECT_EQ(no_hits, target);
}

TEST(TestWordle, TestReportOneHit)
{
	// Arrange
	std::array<wordle::result, wordle::length> one_hit
	{
		{ wordle::result::green, wordle::result::grey, wordle::result::grey, wordle::result::grey, wordle::result::grey }
	};

	// Act
	auto target = wordle::report("super", "stand");

	// Assert
	EXPECT_EQ(one_hit, target);
}

TEST(TestWordle, TestReportTwoHits)
{
	// Arrange
	std::array<wordle::result, wordle::length> two_hits
	{
		{ wordle::result::green, wordle::result::green, wordle::result::grey, wordle::result::grey, wordle::result::grey }
	};

	// Act
	auto target = wordle::report("billy", "birth");

	// Assert
	EXPECT_EQ(two_hits, target);
}

TEST(TestWordle, TestReportThreeHits)
{
	// Arrange
	std::array<wordle::result, wordle::length> three_hits
	{
		{ wordle::result::green, wordle::result::green, wordle::result::green, wordle::result::grey, wordle::result::grey }
	};

	// Act
	auto target = wordle::report("heart", "heavy");

	// Assert
	EXPECT_EQ(three_hits, target);
}

TEST(TestWordle, TestReportFourHits)
{
	// Arrange
	std::array<wordle::result, wordle::length> four_hits
	{
		{ wordle::result::green, wordle::result::green, wordle::result::grey, wordle::result::green, wordle::result::green }
	};

	// Act
	auto target = wordle::report("later", "laser");

	// Assert
	EXPECT_EQ(four_hits, target);
}

TEST(TestWordle, TestReportAllHits)
{
	// Arrange
	std::array<wordle::result, wordle::length> all_hits
	{
		{ wordle::result::green, wordle::result::green, wordle::result::green, wordle::result::green, wordle::result::green }
	};

	// Act
	auto target = wordle::report("where", "where");

	// Assert
	EXPECT_EQ(all_hits, target);
}

TEST(TestWordle, TestReportRepeatedLetters)
{
	// Arrange
	std::array<wordle::result, wordle::length> repeat_letter
	{
		{ wordle::result::green, wordle::result::green, wordle::result::green, wordle::result::green, wordle::result::grey }
	};

	// Act
	auto target = wordle::report("lever", "level");

	// Assert
	EXPECT_EQ(repeat_letter, target);
}


