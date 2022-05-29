#include "stdafx.h"
#include "CCircle.h"

CCircle::CCircle(double x, double y, double radius, uint32_t stroke, uint32_t fill)
{
	CPoint xy{ x, y };
	m_center = xy;
	m_radius = radius;
	m_stroke = stroke;
	m_fill = fill;
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
	return "circle";
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