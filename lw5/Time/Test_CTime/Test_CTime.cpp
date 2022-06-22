#define BOOST_TEST_MODULE Test_CTime
#include <boost/test/included/unit_test.hpp>
#include "/OOP/lw5/Time/Time/CTime.h"
#include <stdexcept>
#include <sstream>

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

//описание тестов нужно доработать
//сейчас оно описывает действие и не то что мы проверяем
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
	//лучше разделить на два тест кейса
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

BOOST_AUTO_TEST_CASE(test_multiplication_simple_case)
{
	CTime time1(5);
	CTime result = time1 * 2;
	BOOST_CHECK_EQUAL(result.GetSeconds(), 10);
	BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(result.GetHours(), 0);
	CTime time2(1000);
	CTime result2 = time2 * -3;
	BOOST_CHECK_EQUAL(result2.GetSeconds(), 0);
	BOOST_CHECK_EQUAL(result2.GetMinutes(), 10);
	BOOST_CHECK_EQUAL(result2.GetHours(), 23);
}

BOOST_AUTO_TEST_CASE(test_multiplication_with_overflow)
{
	CTime time1(80000);
	CTime result = time1 * 2;
	BOOST_CHECK_EQUAL(result.GetSeconds(), 40);
	BOOST_CHECK_EQUAL(result.GetMinutes(), 26);
	BOOST_CHECK_EQUAL(result.GetHours(), 20);
}

BOOST_AUTO_TEST_CASE(test_multiplication_simple_case2)
{
	CTime time1(5);
	CTime result = 5 * time1;
	BOOST_CHECK_EQUAL(result.GetSeconds(), 25);
	BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(result.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_multiplication_simple_case3)
{
	CTime time2(432);
	CTime result2 = time2 * -1000;
	BOOST_CHECK_EQUAL(-432000 % 86400, 0);
	BOOST_CHECK_EQUAL(result2.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(result2.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_multiplication_with_overflow2)
{
	CTime time1(80000);
	CTime result = 2 * time1;
	BOOST_CHECK_EQUAL(result.GetSeconds(), 40);
	BOOST_CHECK_EQUAL(result.GetMinutes(), 26);
	BOOST_CHECK_EQUAL(result.GetHours(), 20);
}

BOOST_AUTO_TEST_CASE(test_division_on_zero)
{
	CTime time1(10);
	BOOST_CHECK_THROW(time1 / 0, std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(test_division_simple_case)
{
	CTime time1(10);
	CTime result = time1 / 2;
	BOOST_CHECK_EQUAL(result.GetSeconds(), 5);
	BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(result.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_division_simple_case2)
{
	CTime time1(1);
	CTime result = time1 / 200000;
	BOOST_CHECK_EQUAL(result.GetSeconds(), 0);
	BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(result.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_division_simple_case3)
{
	CTime time1(0);
	CTime result = time1 / 200000;
	BOOST_CHECK_EQUAL(result.GetSeconds(), 0);
	BOOST_CHECK_EQUAL(result.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(result.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_division_with_negative_number)
{
	CTime time1(10);
	CTime result = time1 / -1;
	BOOST_CHECK_EQUAL(result.GetSeconds(), 50);
	BOOST_CHECK_EQUAL(result.GetMinutes(), 59);
	BOOST_CHECK_EQUAL(result.GetHours(), 23);
}

BOOST_AUTO_TEST_CASE(test_division_with_CTime)
{
	CTime time1(30);
	CTime time2(20);
	int result = time1 / time2;
	BOOST_CHECK_EQUAL(result, 1);
}

BOOST_AUTO_TEST_CASE(test_multiplication_equal_simple_case)
{
	CTime time1(3);
	time1 *= 2;
	BOOST_CHECK_EQUAL(time1.GetSeconds(), 6);
	BOOST_CHECK_EQUAL(time1.GetMinutes(), 0);
	BOOST_CHECK_EQUAL(time1.GetHours(), 0);
}

BOOST_AUTO_TEST_CASE(test_multiplication_equal_with_overflow)
{
	CTime time1(80000);
	time1 *= 2;
	BOOST_CHECK_EQUAL(time1.GetSeconds(), 40);
	BOOST_CHECK_EQUAL(time1.GetMinutes(), 26);
	BOOST_CHECK_EQUAL(time1.GetHours(), 20);
}

BOOST_AUTO_TEST_CASE(test_multiplication_equal_with_negative)
{
	CTime time1(1);
	time1 *= -2;
	BOOST_CHECK_EQUAL(time1.GetSeconds(), 58);
	BOOST_CHECK_EQUAL(time1.GetMinutes(), 59);
	BOOST_CHECK_EQUAL(time1.GetHours(), 23);
}

BOOST_AUTO_TEST_CASE(test_ostream)
{
	CTime time1(86399);

	std::stringstream ss1;
	ss1 << time1;
	std::string str = ss1.str();

	BOOST_CHECK_EQUAL(str, "23:59:59\n");
}

BOOST_AUTO_TEST_CASE(test_istream)
{
	std::stringstream ss1;
	ss1 << "05:05:05";

	CTime time;

	ss1 >> time;

	BOOST_CHECK_EQUAL(time.GetHours(), 05);
	BOOST_CHECK_EQUAL(time.GetMinutes(), 05);
	BOOST_CHECK_EQUAL(time.GetSeconds(), 05);
}

BOOST_AUTO_TEST_CASE(test_operator_compare_equal)
{
	CTime time1(1);
	CTime time2(1);

	BOOST_CHECK(time1 == time2);
	BOOST_CHECK_EQUAL(time1 != time2, false);
}

BOOST_AUTO_TEST_CASE(test_operator_compare_unequal)
{
	CTime time1(1);
	CTime time2(5);

	BOOST_CHECK_EQUAL(time1 == time2, false);
	BOOST_CHECK(time1 != time2);
}

BOOST_AUTO_TEST_CASE(test_operator_compare_more)
{
	CTime time1(1);
	CTime time2(5);
	CTime time3(5);

	BOOST_CHECK_EQUAL(time1 > time2, false);
	BOOST_CHECK(time2 > time1);
	BOOST_CHECK_EQUAL(time2 > time3, false);
}

BOOST_AUTO_TEST_CASE(test_operator_compare_less)
{
	CTime time1(1);
	CTime time2(5);
	CTime time3(5);

	BOOST_CHECK_EQUAL(time2 < time1, false);
	BOOST_CHECK(time1 < time2);
	BOOST_CHECK_EQUAL(time2 < time3, false);
}


BOOST_AUTO_TEST_CASE(test_operator_compare_equal_more)
{
	CTime time1(1);
	CTime time2(5);
	CTime time3(5);

	BOOST_CHECK_EQUAL(time1 >= time2, false);
	BOOST_CHECK(time2 >= time1);
	BOOST_CHECK(time2 >= time3);
}

BOOST_AUTO_TEST_CASE(test_operator_compare_equal_less)
{
	CTime time1(1);
	CTime time2(5);
	CTime time3(5);

	BOOST_CHECK_EQUAL(time2 <= time1, false);
	BOOST_CHECK(time1 <= time2);
	BOOST_CHECK(time2 <= time3);
}