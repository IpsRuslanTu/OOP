#include "stdafx.h"
#include "/OOP/lw4/GeometricShapes/GeometricShapes/CCircle.h"

struct CCircleFixture
{
	double EPSILON = 0.001;

	CCircle circle;

	CCircleFixture()
		: circle({ 1, 2 }, 5, 1, 5)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(circle_methods, CCircleFixture)

BOOST_AUTO_TEST_CASE(circle_get_outline_color)
{
	BOOST_CHECK_EQUAL(circle.GetOutlineColor(), 1);
}

BOOST_AUTO_TEST_CASE(circle_get_fill_color)
{
	BOOST_CHECK_EQUAL(circle.GetFillColor(), 5);
}

BOOST_AUTO_TEST_CASE(circle_get_center)
{
	BOOST_CHECK_EQUAL(circle.GetCenter().x, 1);
	BOOST_CHECK_EQUAL(circle.GetCenter().y, 2);
}

BOOST_AUTO_TEST_CASE(circle_get_area)
{
	BOOST_CHECK(std::abs(circle.GetArea() - 78.53981633) < EPSILON);
}

BOOST_AUTO_TEST_CASE(circle_get_perimeter)
{
	BOOST_CHECK(std::abs(circle.GetPerimeter() - 31.41592) < EPSILON);
}

BOOST_AUTO_TEST_CASE(circle_to_string)
{
	std::string testStr = "shape: circle\ncenter: 1.000000 2.000000\nradius: 5.000000\n"
		"outline color: 1\nfill color: 5\narea: 78.539816\nperimeter: 31.415927\n";

	BOOST_CHECK_EQUAL(circle.ToString(), testStr);
}

BOOST_AUTO_TEST_SUITE_END()

//-----------------------------------------------------------------------------------