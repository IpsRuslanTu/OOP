#pragma once
#include "stdafx.h"
#include "IShape.h"

class CShapesStore
{
public:
	CShapesStore(std::istream& input, std::ostream& output);
	bool AddShape();

	std::shared_ptr<IShape> GetMaxAreaShape();
	std::shared_ptr<IShape> GetMinPerimeterShape();

private:
	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	std::vector<std::shared_ptr<IShape>> m_store;

	bool AddRectangle(std::istream& args);
	bool AddCircle(std::istream& args);
	bool AddTriangle(std::istream& args);
	bool AddLineSegment(std::istream& args);

	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;
};
