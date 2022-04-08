#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../vector/WorkWithVector.h"

SCENARIO("Test function GetFloatVectorFromString")
{
	WHEN("input string is empty")
	{
		THEN("Vector size must be 0")
		{
			REQUIRE(GetFloatVectorFromString("").size() == 0);
		}
	}
	WHEN("input string hasn't numbers")
	{
		THEN("Vector size must be 0")
		{
			REQUIRE(GetFloatVectorFromString("sdfd").size() == 0);
		}
	}
	WHEN("input string has 2 float numbers")
	{
		std::vector<float> test = GetFloatVectorFromString("5.2342 -1.1232");
		std::vector<float> test1{ 5.2342, -1.1232 };
		THEN("Vector size must be 2, all numbers must be in vector correctly")
		{
			REQUIRE(test.size() == 2);
			REQUIRE(test == test1);
		}
	}
}

SCENARIO("Test function MultiplyMaxAndMinElementsOfVector")
{
	WHEN("vector has 1 float numbers")
	{
		THEN("Test results")
		{
			//3. можно разделить на разные тест кейсы + дописать тесты
			REQUIRE(MultiplyMaxAndMinElementsOfVector({ 1.1 }) == 1.21f);
			REQUIRE(MultiplyMaxAndMinElementsOfVector({ 0 }) == 0);
			REQUIRE(MultiplyMaxAndMinElementsOfVector({ -1.1 }) == 1.21f);
		}
		
	}
	WHEN("vector has 2 float numbers")
	{
		THEN("Test results")
		{
			REQUIRE(MultiplyMaxAndMinElementsOfVector({ 1.1, 0 }) == 0);
			REQUIRE(MultiplyMaxAndMinElementsOfVector({ 1.1, 0, -1.1 }) == -1.21f);
		}
	}
	
}

SCENARIO("Test function MultiplyNegativeValuesInVector")
{
	std::vector<float> test{ 1.1, 0 };
	REQUIRE(MultiplyNegativeValuesInVector({ 1.1, 0 }, 2.2) == test);

	std::vector<float> test2{ 2.2, 1 };
	REQUIRE(MultiplyNegativeValuesInVector({ -1.1, 1 }, -2) == test2);
}