#include "stdafx.h"
#include "CShapesStore.h"
#include "CTriangle.h"

using namespace std;

int main()
{
	CShapesStore shapes(cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!shapes.AddShape())
		{
			cout << "Unknown shape!" << endl;
		}
	}

	auto maxAreaShape = shapes.GetMaxAreaShape();
	if (maxAreaShape != nullptr)
	{
		cout << "Shape with max area:\n";
		cout << maxAreaShape->ToString() << endl;
	}
	
	auto minPerimeterShape = shapes.GetMinPerimeterShape();
	if (minPerimeterShape != nullptr)
	{
		cout << "Shape with min perimeter:\n";
		cout << minPerimeterShape->ToString() << endl;
	}

	return 0;
}