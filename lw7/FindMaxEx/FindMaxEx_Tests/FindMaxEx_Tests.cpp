#define BOOST_TEST_MODULE Test_FindMaxEx
#include <boost/test/included/unit_test.hpp>
#include "../FindMaxEx/FindMaxEx.h"
#include <vector>
#include <string>

struct FindMaxExFixture
{
	std::vector<int> arrEmpty;
	std::vector<int> arrInt{ 4, 3, 0, 12, -3, -2 };
	std::vector<float> arrFloat{ -4.4f, -3.4f, 0.0f, -12.3f, -3.344f, -2.211f };
	std::vector<std::string> arrString{ "zero", "hello", "world"};
	std::vector<const char*> arrChars{ "hello", "zero", "world" };

	std::vector<Sportsman> arrSportsmen =
	{
		{"Ivan Ivanov", 172, 72},
		{"Petr Petrov", 167, 73},
		{"Sidor Sidorov", 168, 68},
	};
};

BOOST_FIXTURE_TEST_SUITE(find_max_in_arr, FindMaxExFixture)

BOOST_AUTO_TEST_CASE(empty_arr)
{
	int max;
	BOOST_CHECK(!FindMax(arrEmpty, max, LessThan<int>));
}

BOOST_AUTO_TEST_CASE(find_max_in_int_arr)
{
	int max;
	BOOST_CHECK(FindMax(arrInt, max, LessThan<int>));
	BOOST_CHECK_EQUAL(max, 12);
}

BOOST_AUTO_TEST_CASE(find_max_in_float_arr)
{
	float max;
	BOOST_CHECK(FindMax(arrFloat, max, LessThan<float>));
	BOOST_CHECK_EQUAL(max, 0);
}

BOOST_AUTO_TEST_CASE(find_max_in_string_arr)
{
	std::string max;
	BOOST_CHECK(FindMax(arrString, max, LessThan<std::string>));
	BOOST_CHECK_EQUAL(max, "zero");
}

BOOST_AUTO_TEST_CASE(find_max_in_chars_arr)
{
	const char* max;
	BOOST_CHECK(FindMax(arrChars, max, LessThan<std::string>));
	BOOST_CHECK_EQUAL(max, "zero");
}

BOOST_AUTO_TEST_CASE(find_sportsman_by_height)
{
	Sportsman max;
	FindMax(arrSportsmen, max, ComparatorHeight);
	BOOST_CHECK_EQUAL(max.name, "Ivan Ivanov");
}

BOOST_AUTO_TEST_CASE(find_arr2_by_weight)
{
	Sportsman max;
	FindMax(arrSportsmen, max, ComparatorWeight);
	BOOST_CHECK_EQUAL(max.name, "Petr Petrov");
}

BOOST_AUTO_TEST_SUITE_END()