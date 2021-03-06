#include "CTriangle.h"
#include "stdafx.h"

using namespace std;

namespace
{
	const double& AssureNotNegative(const double& value, const string& argName = string())
	{
		if (value >= 0)
		{
			return value;
		}
		throw invalid_argument(argName.empty() ? "Argument" : argName + " can not be negative.");
	}
}

#define ASSURE_NOT_NEGATIVE(value) AssureNotNegative((value), #value)

CTriangle::CTriangle(double side1, double side2, double side3)
	: m_side1(ASSURE_NOT_NEGATIVE(side1))
	, m_side2(ASSURE_NOT_NEGATIVE(side2))
	, m_side3(ASSURE_NOT_NEGATIVE(side3))
{
	ValidateSideLength(side1, side2, side3, 1, 2, 3);
	ValidateSideLength(side2, side1, side3, 2, 1, 3);
	ValidateSideLength(side3, side1, side2, 3, 1, 2);
}

double CTriangle::GetSide1()const
{
	return m_side1;
}

double CTriangle::GetSide2()const
{
	return m_side2;
}

double CTriangle::GetSide3()const
{
	return m_side3;
}

double CTriangle::GetPerimeter()const
{
	return m_side1 + m_side2 + m_side3;
}

double CTriangle::GetArea()const
{
	double p = GetPerimeter() / 2;
	return sqrt(p * (p - m_side1) * (p - m_side2) * (p - m_side3));
}

void CTriangle::ValidateSideLength(
	double sideToCheck, double side1, double side2,
	int checkedSideIndex, int side1Index, int side2Index)
{
	if (sideToCheck > side1 + side2)
	{
		throw domain_error((boost::format("Side %1% can not be greater than sum of side %2% and side %3%")
			% checkedSideIndex % side1Index % side2Index).str());
	}
}