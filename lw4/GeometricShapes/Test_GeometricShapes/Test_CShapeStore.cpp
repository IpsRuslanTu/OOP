#include "stdafx.h"
#include "/OOP/lw4/GeometricShapes/GeometricShapes/CShapesStore.h"
#include <sstream>
#include <boost/optional.hpp>

using namespace std;
using boost::optional;
using boost::none;

struct CShapesStoreDependencies
{
	double EPSILON = 0.001;

	stringstream input;
	stringstream output;
};

struct CShapesStoreFixture : CShapesStoreDependencies
{
	CShapesStore store;

	CShapesStoreFixture()
		: store(input, output)
	{
	}

	void VerifyCommandHandling(const string& command, const string& expectedOutput)
	{
		output = stringstream();
		input = stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(store.AddShape());
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(CShapesStore_methods, CShapesStoreFixture)

BOOST_AUTO_TEST_CASE(added_rectangle)
{
	VerifyCommandHandling("rectangle 2 2 2 2 2 2", "rectangle added\n");
	VerifyCommandHandling("rectangle 2 2 2 2 2", "Error. Check parameters\n");
}

BOOST_AUTO_TEST_CASE(get_shape_max_area)
{
	VerifyCommandHandling("rectangle 2 2 2 2 2 2", "rectangle added\n");
	VerifyCommandHandling("circle 1 1 5 2 2", "circle added\n");
	VerifyCommandHandling("triangle 0 1 5 5 10 0 3 3", "triangle added\n");
	
	BOOST_CHECK(std::abs(store.GetMaxAreaShape()->GetArea() - 78.539816) < EPSILON);
	BOOST_CHECK(std::abs(store.GetMaxAreaShape()->GetPerimeter() - 31.415926) < EPSILON);
}

//можно проверить кейс без фигур
//что будет если одинаковые, может написать тест?
BOOST_AUTO_TEST_CASE(get_shape_min_perimeter)
{
	VerifyCommandHandling("rectangle 2 2 2 2 2 2", "rectangle added\n");
	VerifyCommandHandling("circle 1 1 5 2 2", "circle added\n");
	VerifyCommandHandling("triangle 0 1 5 5 10 0 3 3", "triangle added\n");

	BOOST_CHECK_EQUAL(store.GetMinPerimeterShape()->GetArea(), 4);
	BOOST_CHECK_EQUAL(store.GetMinPerimeterShape()->GetPerimeter(), 8);
}

BOOST_AUTO_TEST_SUITE_END()