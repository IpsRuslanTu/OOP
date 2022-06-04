#define BOOST_TEST_MODULE Test_CTime
#include <boost/test/included/unit_test.hpp>
#include "/OOP/lw5/Time/Time/CTime.h"
#include <stdexcept>

struct CorrectTimeFixture
{
	CTime time;

	CorrectTimeFixture()
		: time(4136) // 1:8:56
	{}

	~CorrectTimeFixture() = default;
};

BOOST_FIXTURE_TEST_SUITE(test_methods_of_CTime_if_time_is_correct, CorrectTimeFixture)

BOOST_AUTO_TEST_CASE(test_method_get_hours)
{
	BOOST_CHECK_EQUAL(time.GetHours(), 1);
}

BOOST_AUTO_TEST_CASE(test_method_get_minutes)
{
	BOOST_CHECK_EQUAL(time.GetMinutes(), 8);
}

BOOST_AUTO_TEST_CASE(test_method_get_seconds)
{
	BOOST_CHECK_EQUAL(time.GetSeconds(), 56);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_CASE(input_incorrect_hours)
{
	BOOST_CHECK_THROW(CTime time1(24, 15, 6), std::invalid_argument);
	BOOST_CHECK_THROW(CTime time1(-1, 15, 6), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(input_incorrect_minutes)
{
	BOOST_CHECK_THROW(CTime time1(23, 60, 6), std::invalid_argument);
	BOOST_CHECK_THROW(CTime time1(23, -1, 6), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(input_incorrect_seconds)
{
	BOOST_CHECK_THROW(CTime time1(0, 15, 60), std::invalid_argument);
	BOOST_CHECK_THROW(CTime time1(0, 15, -1), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(input_incorrect_seconds_as_one_parameter)
{
	BOOST_CHECK_THROW(CTime time1(-1), std::invalid_argument);
	BOOST_CHECK_THROW(CTime time1(86400), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(valid_parameters)
{
	BOOST_CHECK_NO_THROW(CTime time1());
	BOOST_CHECK_NO_THROW(CTime time2(0));
	BOOST_CHECK_NO_THROW(CTime time3(86399));
	BOOST_CHECK_NO_THROW(CTime time4(0, 0, 0));
	BOOST_CHECK_NO_THROW(CTime time4(23, 59, 59));
}

BOOST_AUTO_TEST_CASE(test_increment)
{
	CTime time1(86399);
	CTime time11 = ++time1;
	BOOST_CHECK_EQUAL(time11.GetSeconds(), 0);
	BOOST_CHECK_EQUAL(time11.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(time11.GetHours(), 0);
	CTime time12 = time11++;
	BOOST_CHECK_EQUAL(time12.GetSeconds(), 0);
	BOOST_CHECK_EQUAL(time12.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(time12.GetHours(), 0);
	BOOST_CHECK_EQUAL(time11.GetSeconds(), 1);
	BOOST_CHECK_EQUAL(time11.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(time11.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_decrement)
{
	CTime time1(2);
	CTime time11 = --time1;
	BOOST_CHECK_EQUAL(time11.GetSeconds(), 1);
	CTime time12 = time11--;
	BOOST_CHECK_EQUAL(time12.GetSeconds(), 1);
	BOOST_CHECK_EQUAL(time12.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(time12.GetHours(), 0);
	time11--;
	BOOST_CHECK_EQUAL(time11.GetSeconds(), 59);
	BOOST_CHECK_EQUAL(time11.GetMinutes(), 59);
	BOOST_CHECK_EQUAL(time11.GetHours(), 23);
}

BOOST_AUTO_TEST_CASE(test_plus_simple_case)
{
	CTime time1(1);
	CTime time2(2);
	CTime result = time1 + time2;
	BOOST_CHECK_EQUAL(result.GetSeconds(), 3);
	BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(result.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_plus_with_overflow)
{
	CTime time1(2);
	CTime time2(23, 59, 59);
	CTime result = time1 + time2;
	BOOST_CHECK_EQUAL(result.GetSeconds(), 1);
	BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(result.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_minus_simple_case)
{
	CTime time1(8);
	CTime time2(2);
	CTime result = time1 - time2;
	BOOST_CHECK_EQUAL(result.GetSeconds(), 6);
	BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(result.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_minus_with_overflow)
{
	CTime time1(5);
	CTime time2(10);
	CTime result = time1 - time2;
	BOOST_CHECK_EQUAL(result.GetSeconds(), 55);
	BOOST_CHECK_EQUAL(result.GetMinutes(), 59);
	BOOST_CHECK_EQUAL(result.GetHours(), 23);
}

BOOST_AUTO_TEST_CASE(test_plus_equal_simple_case)
{
	CTime time1(2);
	CTime time2(5);
	time1 += time2;
	BOOST_CHECK_EQUAL(time1.GetSeconds(), 7);
	BOOST_CHECK_EQUAL(time1.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(time1.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_plus_equal_with_overflow)
{
	CTime time1(2);
	CTime time2(23, 59, 59);
	time1 += time2;
	BOOST_CHECK_EQUAL(time1.GetSeconds(), 1);
	BOOST_CHECK_EQUAL(time1.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(time1.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_minus_equal_simple_case)
{
	CTime time1(7);
	CTime time2(2);
	time1 -= time2;
	BOOST_CHECK_EQUAL(time1.GetSeconds(), 5);
	BOOST_CHECK_EQUAL(time1.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(time1.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_minus_equal_with_overflow)
{
	CTime time1(5);
	CTime time2(10);
	time1 -= time2;
	BOOST_CHECK_EQUAL(time1.GetSeconds(), 55);
	BOOST_CHECK_EQUAL(time1.GetMinutes(), 59);
	BOOST_CHECK_EQUAL(time1.GetHours(), 23);
}