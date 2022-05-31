#include "stdafx.h"
#include "/OOP/lw4/GeometricShapes/GeometricShapes/CRectangle.h"

struct CRectangleFixture
{
	double EPSILON = 0.001;

	CRectangle rect;

	CRectangleFixture()
		: rect({ 1, 2 }, 5, 4, 1, 5)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(rectangle_methods, CRectangleFixture)

BOOST_AUTO_TEST_CASE(rectangle_get_outline_color)
{
	BOOST_CHECK_EQUAL(rect.GetOutlineColor(), 1);
}

BOOST_AUTO_TEST_CASE(rectangle_get_fill_color)
{
	BOOST_CHECK_EQUAL(rect.GetFillColor(), 5);
}

BOOST_AUTO_TEST_CASE(rectangle_get_width)
{
	BOOST_CHECK_EQUAL(rect.GetWidth(), 5);
}

BOOST_AUTO_TEST_CASE(rectangle_get_height)
{
	BOOST_CHECK_EQUAL(rect.GetHeight(), 4);
}

BOOST_AUTO_TEST_CASE(rectangle_get_left_top)
{
	BOOST_CHECK_EQUAL(rect.GetLeftTop().x, 1);
	BOOST_CHECK_EQUAL(rect.GetLeftTop().y, 2);
}

BOOST_AUTO_TEST_CASE(rectangle_get_right_bottom)
{
	BOOST_CHECK_EQUAL(rect.GetRightBottom().x, 6);
	BOOST_CHECK_EQUAL(rect.GetRightBottom().y, 6);
}

BOOST_AUTO_TEST_CASE(rectangle_get_area)
{
	BOOST_CHECK_EQUAL(rect.GetArea(), 20);
}

BOOST_AUTO_TEST_CASE(rectangle_get_perimeter)
{
	BOOST_CHECK_EQUAL(rect.GetPerimeter(), 18);
}

BOOST_AUTO_TEST_CASE(rectangle_to_string)
{
	std::string testStr = "shape: rectangle\nleft top: 1.000000 2.000000\nwidth: 5.000000\n"
		"height: 4.000000\noutline color: 1\nfill color: 5\narea: 20.000000\n"
		"perimeter: 18.000000\n";

	BOOST_CHECK_EQUAL(rect.ToString(), testStr);
}

BOOST_AUTO_TEST_SUITE_END()

//-----------------------------------------------------------------------------------