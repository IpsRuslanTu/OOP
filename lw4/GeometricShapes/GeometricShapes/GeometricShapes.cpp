#include "stdafx.h"
#include "CShapesStore.h"
#include "CTriangle.h"

using namespace std;

int main()
{
	//CRectangle rect(1, 2, 5, 6, 7, 8);
	//vector<IShape*> arr;
	//arr.push_back(&rect);

	CTriangle tr(1, 1, 2, 2, 10, 0, 1, 1);

	cout << tr.GetPerimeter() << " " << tr.GetArea();

	//CShapesStore shapes(cin, cout);

	//while (!cin.eof() && !cin.fail())
	//{
	//	cout << "> ";
	//	if (!shapes.AddShape())
	//	{
	//		cout << "Unknown shape!" << endl;
	//	}
	//}

	return 0;
}