#include "stdafx.h"
#include "CCircle.h"

using namespace std;

CCircle::CCircle(CPoint point, double radius, uint32_t stroke, uint32_t fill)
	: m_center(point)
	, m_radius(radius)
	, m_stroke(stroke)
	, m_fill(fill)
{
}

double CCircle::GetArea()
{
	return M_PI * m_radius * m_radius;
}

double CCircle::GetPerimeter()
{
	return 2 * M_PI * m_radius;
}

std::string CCircle::ToString()
{
	string info = "shape: circle\ncenter: "
		+ to_string(m_center.x) + " " + to_string(m_center.y)
		+ "\nradius: " + to_string(m_radius)
		+ "\noutline color: " + to_string(m_stroke)
		+ "\nfill color: " + to_string(m_fill)
		+ "\narea: " + to_string(GetArea())
		+ "\nperimeter: " + to_string(GetPerimeter()) + "\n";

	return info;
}

uint32_t CCircle::GetOutlineColor()
{
	return m_stroke;
}

uint32_t CCircle::GetFillColor()
{
	return m_fill;
}

CPoint CCircle::GetCenter()
{
	return m_center;
}

double CCircle::GetRadius()
{
	return m_radius;
}