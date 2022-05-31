#include "stdafx.h"
#include "/OOP/lw4/GeometricShapes/GeometricShapes/CLineSegment.h"

struct CLineSegmentFixture
{
	double EPSILON = 0.001;

	CLineSegment line;

	CLineSegmentFixture()
		: line({ 1, 1 }, { 5, 5 }, 1)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(line_methods, CLineSegmentFixture)

BOOST_AUTO_TEST_CASE(line_get_outline_color)
{
	BOOST_CHECK_EQUAL(line.GetOutlineColor(), 1);
}

BOOST_AUTO_TEST_CASE(line_get_points)
{
	BOOST_CHECK_EQUAL(line.GetStartPoint().x, 1);
	BOOST_CHECK_EQUAL(line.GetStartPoint().y, 1);
	BOOST_CHECK_EQUAL(line.GetEndPoint().x, 5);
	BOOST_CHECK_EQUAL(line.GetEndPoint().y, 5);
}

BOOST_AUTO_TEST_CASE(line_get_area)
{
	BOOST_CHECK_EQUAL(line.GetArea(), 0);
}

BOOST_AUTO_TEST_CASE(line_get_perimeter)
{
	BOOST_CHECK(line.GetPerimeter() - 5.656854 < EPSILON);
}

BOOST_AUTO_TEST_CASE(line_to_string)
{
	std::string testStr = "shape: line\nstart point: 1.000000 1.000000\n"
		"end point: 5.000000 5.000000\noutline color: 1\nlenght: 5.656854\n";

	BOOST_CHECK_EQUAL(line.ToString(), testStr);
}

BOOST_AUTO_TEST_SUITE_END()

//-----------------------------------------------------------------------------------