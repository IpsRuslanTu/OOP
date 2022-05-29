#pragma once
#include "CPoint.h"
#include "CLineSegment.h"
#include "ISolidShape.h"

class CTriangle : public ISolidShape
{
public:
	CTriangle(CPoint p1, CPoint p2, CPoint p3, uint32_t stroke, uint32_t fill);
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;
	uint32_t GetOutlineColor() override;
	uint32_t GetFillColor() override;
	CPoint GetVertex1();
	CPoint GetVertex2();
	CPoint GetVertex3();

private:
	CPoint m_vertex1;
	CPoint m_vertex2;
	CPoint m_vertex3;
	uint32_t m_stroke;
	uint32_t m_fill;

	std::vector<double> GetSides();
};
