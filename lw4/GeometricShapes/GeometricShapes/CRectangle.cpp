#include "CRectangle.h"

CRectangle::CRectangle(double x, double y, double width, double height, uint32_t stroke, uint32_t fill)
{
	CPoint xy{x , y};
	m_leftTop = xy;
	m_width = width;
	m_height = height;
	m_stroke = stroke;
	m_fill = fill;
}

double CRectangle::GetArea()
{
	return m_width * m_height;
}

double CRectangle::GetPerimeter()
{
	return 2 * (m_width + m_height);
}

std::string CRectangle::ToString()
{
	return "rectangle";
}

uint32_t CRectangle::GetOutlineColor()
{
	return m_stroke;
}

uint32_t CRectangle::GetFillColor()
{
	return m_fill;
}

CPoint CRectangle::GetLeftTop()
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom()
{
	CPoint rightBottom{ m_leftTop.x + m_width, m_leftTop.y + m_height };

	return rightBottom;
}

double CRectangle::GetWidth()
{
	return m_width;
}

double CRectangle::GetHeight()
{
	return m_height;
}