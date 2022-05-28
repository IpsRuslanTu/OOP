#include <iostream>
#include <vector>
#include "CRectangle.h"
#include "CCircle.h"
#include <variant>

using namespace std;

int main()
{
	CRectangle rect(1, 2, 5, 6, 7, 8);

	CCircle circle(1, 1, 8, 3, 4);

	vector<IShape*> arr;

	arr.push_back(&rect);

	arr.push_back(&circle);

	for (int i = 0; i < arr.size(); ++i)
	{
		cout << arr[i]->GetArea() << endl;
	}

    return 0;
}