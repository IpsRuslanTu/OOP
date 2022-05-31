#include "CTriangle.h"

using namespace std;

CTriangle::CTriangle(CPoint p1, CPoint p2, CPoint p3, uint32_t stroke, uint32_t fill)
	: m_vertex1(p1)
	, m_vertex2(p2)
	, m_vertex3(p3)
	, m_stroke(stroke)
	, m_fill(fill)
{
}

double CTriangle::GetArea()
{
	double halfPerimeter = GetPerimeter() / 2;
	std::vector<double> sides = GetSides();

	double temp = 1;
	for (int i = 0; i < sides.size(); ++i)
	{
		temp *= halfPerimeter - sides[i];
	}

	double area = sqrt(temp * halfPerimeter);

	return area;
}

double CTriangle::GetPerimeter()
{
	double perimeter = 0;
	std::vector<double> sides = GetSides();

	for (int i = 0; i < sides.size(); ++i)
	{
		perimeter += sides[i];
	}

	return perimeter;
}

std::string CTriangle::ToString()
{
	string info = "shape: triangle\npoint1: "
		+ to_string(m_vertex1.x) + " " + to_string(m_vertex1.y)
		+ "\npoint2: " + to_string(m_vertex2.x) + " " + to_string(m_vertex2.y)
		+ "\npoint3: " + to_string(m_vertex3.x) + " " + to_string(m_vertex3.y)
		+ "\noutline color: " + to_string(m_stroke)
		+ "\nfill color: " + to_string(m_fill)
		+ "\narea: " + to_string(GetArea())
		+ "\nperimeter: " + to_string(GetPerimeter()) + "\n";

	return info;
}

uint32_t CTriangle::GetOutlineColor()
{
	return m_stroke;
}

uint32_t CTriangle::GetFillColor()
{
	return m_fill;
}

CPoint CTriangle::GetVertex1()
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2()
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3()
{
	return m_vertex3;
}

std::vector<double> CTriangle::GetSides()
{
	CLineSegment side1(m_vertex1, m_vertex2, m_stroke);
	CLineSegment side2(m_vertex1, m_vertex3, m_stroke);
	CLineSegment side3(m_vertex2, m_vertex3, m_stroke);

	std::vector<double> sides{ side1.GetPerimeter(), side2.GetPerimeter(), side3.GetPerimeter() };

	return sides;
}
