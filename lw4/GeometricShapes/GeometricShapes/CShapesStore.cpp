#include "CShapesStore.h"
#include "CRectangle.h"
#include "CCircle.h"
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
using namespace std::placeholders;

CShapesStore::CShapesStore(istream& input, ostream& output)
	: m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "rectangle", bind(&CShapesStore::AddRectangle, this, _1) },
		  { "circle", bind(&CShapesStore::AddCircle, this, _1) },
		  { "triangle", bind(&CShapesStore::AddTriangle, this, _1) }
	  })
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

bool CShapesStore::AddRectangle(std::istream& args)
{
	double x = 0, y = 0, width = 0, height = 0;
	uint32_t stroke = 0, fill = 0;

	try
	{
		args >> x;
		m_output << x << endl;
		args >> y;
		m_output << y << endl;
		args >> width;
		m_output << width << endl;
		args >> height;
		m_output << height << endl;
		args >> stroke;
		m_output << stroke << endl;
		args >> fill;
		m_output << fill << endl;
	}
	catch (const exception& e)
	{
		m_output << "invalid parameters for rectangle" << endl;
		return false;
	}

	CRectangle rect(x, y, width, height, stroke, fill);

	m_store.push_back(&rect);

	m_output << "rectangle added" << endl;
	return true;
}

bool CShapesStore::AddCircle(std::istream& args)
{
	double x, y, radius;
	uint32_t stroke, fill;

	try
	{
		args >> x;
		args >> y;
		args >> radius;
		args >> stroke;
		args >> fill;
	}
	catch (const exception& e)
	{
		m_output << "invalid parameters for circle" << endl;
		return false;
	}

	CCircle circle(x, y, radius, stroke, fill);

	m_store.push_back(&circle);
	m_output << "circle added" << endl;
	return true;
}

bool CShapesStore::AddTriangle(std::istream& args)
{
	//m_store.push_back(&circle);
	m_output << "triangle added" << endl;
	return true;
}