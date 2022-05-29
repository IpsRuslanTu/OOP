#pragma once
#include "stdafx.h"
#include "IShape.h"

class CShapesStore
{
public:
	CShapesStore(std::istream& input, std::ostream& output);
	bool AddShape();

private:
	using Handler = std::function<bool(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	std::vector<IShape*> m_store;

	bool AddRectangle(std::istream& args);
	bool AddCircle(std::istream& args);
	bool AddTriangle(std::istream& args);

	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;
};
