#pragma once
#include "stdafx.h"
#include "CPoint.h"
#include "IShape.h"

class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint start, CPoint end, uint32_t stroke);
	double GetArea() override;
	double GetPerimeter() override;
	std::string ToString() override;
	uint32_t GetOutlineColor() override;

	CPoint GetStartPoint();
	CPoint GetEndPoint();

private:
	CPoint m_start;
	CPoint m_end;
	uint32_t m_stroke;
};
