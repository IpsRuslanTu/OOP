#pragma once
#include "ISolidShape.h"
#include "CPoint.h"

class CCircle : public ISolidShape
{
public:
	CCircle(double x, double y, double radius, uint32_t stroke, uint32_t fill);
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;
	uint32_t GetOutlineColor() override;
	uint32_t GetFillColor() override;
	CPoint GetCenter();
	double GetRadius();

private:
	CPoint m_center;
	double m_radius;
	uint32_t m_stroke;
	uint32_t m_fill;
};
