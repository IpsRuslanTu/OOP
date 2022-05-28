#include <iostream>
#include <vector>
#include "CShapesStore.h"

using namespace std;

int main()
{
	//CRectangle rect(1, 2, 5, 6, 7, 8);
	//vector<IShape*> arr;
	//arr.push_back(&rect);

	CShapesStore shapes(cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!shapes.AddShape())
		{
			cout << "Unknown shape!" << endl;
		}
	}

	return 0;
}