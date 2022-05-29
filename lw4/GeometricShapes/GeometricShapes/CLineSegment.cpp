#include "CLineSegment.h"

CLineSegment::CLineSegment(CPoint start, CPoint end, uint32_t stroke)
	: m_start(start)
	, m_end(end)
	, m_stroke(stroke)
{
}

double CLineSegment::GetArea()
{
	return 0;
}

double CLineSegment::GetPerimeter()
{
	double sideX = pow(m_start.x - m_end.x, 2);
	double sideY = pow(m_start.y - m_end.y, 2);
	double lenght = sqrt(sideX + sideY);

	return lenght;
}

std::string CLineSegment::ToString()
{
	return "line segment";
}

uint32_t CLineSegment::GetOutlineColor()
{
	return m_stroke;
}

CPoint CLineSegment::GetStartPoint()
{
	return m_start;
}

CPoint CLineSegment::GetEndPoint()
{
	return m_end;
}