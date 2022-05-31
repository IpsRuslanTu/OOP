#include "stdafx.h"
#include "CRectangle.h"

using namespace std;

CRectangle::CRectangle(CPoint point, double width, double height, uint32_t stroke, uint32_t fill)
	: m_leftTop(point)
	, m_width(width)
	, m_height(height)
	, m_stroke(stroke)
	, m_fill(fill)
{
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
	string info = "shape: rectangle\nleft top: "
		+ to_string(m_leftTop.x) + " " + to_string(m_leftTop.y)
		+ "\nwidth: " + to_string(m_width)
		+ "\nheight: " + to_string(m_height)
		+ "\noutline color: " + to_string(m_stroke)
		+ "\nfill color: " + to_string(m_fill)
		+ "\narea: " + to_string(GetArea())
		+ "\nperimeter: " + to_string(GetPerimeter()) + "\n";

	return info;
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