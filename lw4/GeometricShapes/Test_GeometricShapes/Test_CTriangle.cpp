#include "stdafx.h"
#include "/OOP/lw4/GeometricShapes/GeometricShapes/CTriangle.h"

struct CTriangleFixture
{
	double EPSILON = 0.001;

	CTriangle triangle;

	CTriangleFixture()
		: triangle({ 1, 1 }, { 5, 5 }, {10, 0}, 1, 5)
	{
	}
};

BOOST_FIXTURE_TEST_SUITE(triangle_methods, CTriangleFixture)

BOOST_AUTO_TEST_CASE(triangle_get_outline_color)
{
	BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), 1);
}

BOOST_AUTO_TEST_CASE(triangle_get_fill_color)
{
	BOOST_CHECK_EQUAL(triangle.GetFillColor(), 5);
}

BOOST_AUTO_TEST_CASE(triangle_get_vertex)
{
	BOOST_CHECK_EQUAL(triangle.GetVertex1().x, 1);
	BOOST_CHECK_EQUAL(triangle.GetVertex1().y, 1);
	BOOST_CHECK_EQUAL(triangle.GetVertex2().x, 5);
	BOOST_CHECK_EQUAL(triangle.GetVertex2().y, 5);
	BOOST_CHECK_EQUAL(triangle.GetVertex3().x, 10);
	BOOST_CHECK_EQUAL(triangle.GetVertex3().y, 0);
}

BOOST_AUTO_TEST_CASE(triangle_get_area)
{
	BOOST_CHECK(std::abs(triangle.GetArea() - 20.000000) < EPSILON);
}

BOOST_AUTO_TEST_CASE(triangle_get_perimeter)
{
	BOOST_CHECK(std::abs(triangle.GetPerimeter() - 21.783307) < EPSILON);
}

BOOST_AUTO_TEST_CASE(triangle_to_string)
{
	std::string testStr = "shape: triangle\npoint1: 1.000000 1.000000\n"
		"point2: 5.000000 5.000000\npoint3: 10.000000 0.000000\n"
		"outline color: 1\nfill color: 5\narea: 20.000000\n"
		"perimeter: 21.783307\n";

	BOOST_CHECK_EQUAL(triangle.ToString(), testStr);
}

BOOST_AUTO_TEST_SUITE_END()