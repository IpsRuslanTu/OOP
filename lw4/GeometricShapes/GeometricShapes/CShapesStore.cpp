#include "stdafx.h"
#include "CShapesStore.h"
#include "CCircle.h"
#include "CRectangle.h"
#include "CTriangle.h"

using namespace std;
using namespace std::placeholders;

CShapesStore::CShapesStore(istream& input, ostream& output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({ { "rectangle", bind(&CShapesStore::AddRectangle, this, _1) },
		  { "circle", bind(&CShapesStore::AddCircle, this, _1) },
		  { "triangle", bind(&CShapesStore::AddTriangle, this, _1) },
		  { "line", bind(&CShapesStore::AddLineSegment, this, _1) } })
{
}

bool CShapesStore::AddShape()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}

	return false;
}

bool CShapesStore::AddRectangle(istream& args)
{
	double x = 0, y = 0, width = 0, height = 0;
	uint32_t stroke = 0, fill = 0;

	args >> x;
	args >> y;
	args >> width;
	args >> height;
	args >> stroke;
	args >> fill;

	if (args.fail())
	{
		m_output << "Error. Check parameters\n";

		return true;
	}

	CPoint point{ x, y };

	auto rect = make_shared<CRectangle>(point, width, height, stroke, fill);

	m_store.emplace_back(move(rect));

	m_output << "rectangle added" << endl;
	return true;
}

bool CShapesStore::AddCircle(istream& args)
{
	double x, y, radius;
	uint32_t stroke, fill;

	args >> x;
	args >> y;
	args >> radius;
	args >> stroke;
	args >> fill;

	if (args.fail())
	{
		m_output << "Error. Check parameters\n";

		return true;
	}

	CPoint point{ x, y };
	auto circle = make_shared<CCircle>(point, radius, stroke, fill);

	m_store.emplace_back(move(circle));

	m_output << "circle added" << endl;
	return true;
}

bool CShapesStore::AddTriangle(istream& args)
{
	double x1, y1, x2, y2, x3, y3;
	uint32_t stroke, fill;

	args >> x1;
	args >> y1;
	args >> x2;
	args >> y2;
	args >> x3;
	args >> y3;

	args >> stroke;
	args >> fill;

	if (args.fail())
	{
		m_output << "Error. Check parameters\n";

		return true;
	}

	CPoint p1{ x1, y1 };
	CPoint p2{ x2, y2 };
	CPoint p3{ x3, y3 };

	auto triangle = make_shared<CTriangle>(p1, p2, p3, stroke, fill);

	m_store.emplace_back(move(triangle));

	m_output << "triangle added" << endl;
	return true;
}

bool CShapesStore::AddLineSegment(std::istream& args)
{
	double x1, y1, x2, y2;
	uint32_t stroke;

	args >> x1;
	args >> y1;
	args >> x2;
	args >> y2;

	args >> stroke;

	if (args.fail())
	{
		m_output << "Error. Check parameters\n";

		return true;
	}

	CPoint p1{ x1, y1 };
	CPoint p2{ x2, y2 };
	auto line = make_shared<CLineSegment>(p1, p2, stroke);

	m_store.emplace_back(move(line));

	m_output << "line added" << endl;
	return true;
}

shared_ptr<IShape> CShapesStore::GetMaxAreaShape()
{
	if (m_store.empty())
	{
		m_output << "Shapes are missing.\nThere is no way to find a shape with max area\n";
		return nullptr;
	}

	shared_ptr<IShape> maxAreaShape = m_store[0];

	for (auto& shape : m_store)
	{
		maxAreaShape = maxAreaShape->GetArea() > shape->GetArea()
			? maxAreaShape
			: shape;
	}

	return maxAreaShape;
}

shared_ptr<IShape> CShapesStore::GetMinPerimeterShape()
{
	if (m_store.empty())
	{
		m_output << "Shapes are missing.\nThere is no way to find a shape with min perimeter\n";
		return nullptr;
	}

	auto minPerimeterShape = m_store[0];

	for (auto& shape : m_store)
	{
		minPerimeterShape = minPerimeterShape->GetPerimeter() < shape->GetPerimeter()
			? minPerimeterShape
			: shape;
	}

	return minPerimeterShape;
}