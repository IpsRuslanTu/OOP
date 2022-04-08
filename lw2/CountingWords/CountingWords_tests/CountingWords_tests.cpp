#include <iostream>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"
#include "../CountingWords/FunctionsForMap.h"

SCENARIO("Test function AddWordToMap")
{
	GIVEN("Init empty map")
	{
		std::map <std::string, unsigned int> mapWords;
		std::map <std::string, unsigned int> controlMap1 = { { "hello", 1 } };
		std::map <std::string, unsigned int> controlMap2 = { { "hello", 1 }, { "cat", 1 }};
		std::map <std::string, unsigned int> controlMap3 = { { "hello", 2 }, { "cat", 1 } };

		WHEN("Add 1 word")
		{
			THEN("Init map would contain this word and count 1")
			{
				REQUIRE(AddWordToMap(mapWords, "hello") == controlMap1);
			}
		}

		mapWords = AddWordToMap(mapWords, "hello");

		WHEN("Add another other word")
		{
			THEN("Init map must have 2 words and keys 1")
			{
				REQUIRE(AddWordToMap(mapWords, "cat") == controlMap2);
			}
		}

		mapWords = AddWordToMap(mapWords, "cat");
		
		WHEN("Add a repeating word")
		{
			THEN("Init map must have 'hello': 2, and 'cat': 1")
			{
				REQUIRE(AddWordToMap(mapWords, "hello") == controlMap3);
			}
		}
	}	
}

SCENARIO("Test function AddAndCountWordsToMap")
{
	std::map <std::string, unsigned int> mapWords;
	WHEN("")
	{
		THEN("")
		{

		}
	}
}