#include <iostream>
#include <sstream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "Reverse.h"

SCENARIO("Reversing of empty string gives empty string")
{
	REQUIRE(Reverse("").empty());
}

SCENARIO("Reversing of string of 1 character is the string itself")
{
	REQUIRE(Reverse("a") == "a");
}

SCENARIO("Reverse of string longer than 1 character")
{
	REQUIRE(Reverse("1234") == "4321");
}

SCENARIO("ReverseLines")
{
	std::ostringstream output;
	WHEN("Input string is empty")
	{
		std::istringstream input("");
		THEN("Output string is also is empty")
		{
			ReverseLines(input, output);
			CHECK(output.str().empty());
			CHECK(input.eof());
		}
	}
	
	WHEN("Input string contains one line")
	{
		std::istringstream input("1 line");
		THEN("output stream contains the line reversed")
		{
			ReverseLines(input, output);
			CHECK(output.str() == "enil 1");
			CHECK(input.eof());
		}
	}

	WHEN("Input string contains several lines")
	{
		std::istringstream input("1 line\n2 line");
		THEN("output stream contains the line reversed")
		{
			ReverseLines(input, output);
			CHECK(output.str() == "enil 1\nenil 2");
			CHECK(input.eof());
		}
	}

	WHEN("Input stream contains EOL in the end")
	{
		std::istringstream input("1 line\n2 line\n");
		THEN("output stream contains EOL is the end as well")
		{
			ReverseLines(input, output);
			CHECK(output.str() == "enil 1\nenil 2\n");
			CHECK(input.eof());
		}
	}
}