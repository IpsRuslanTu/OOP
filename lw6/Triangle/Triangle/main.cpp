#include "stdafx.h"
#include "CTriangle.h"

using namespace std;

vector<double> GetTriangleSidesFromStream(istream& cin)
{
	const int countOfSidesTriangle = 3;
	vector<double> sides;

	string input;
	getline(cin, input);
	istringstream strm(input);

	for (int i = 0; i < countOfSidesTriangle; ++i)
	{
		double side;
		strm >> side;
		sides.push_back(side);

		if (strm.fail())
		{
			throw std::invalid_argument("Invalid argument in position " + to_string(i + 1));
		}
	}

	return sides;
}

int main()
{
	while (!cin.eof() && !cin.fail())
	{
		cout << "Input dimensions of triangle's sides: ";

		try {
			vector<double> sides = GetTriangleSidesFromStream(cin);

			CTriangle triangle(sides[0], sides[1], sides[2]);

			cout << "Triangle's area = " << triangle.GetArea() << endl;
			cout << "Triangle's perimeter = " << triangle.GetPerimeter() << endl;

		}
		catch (exception& error)
		{
			cout << error.what() << endl;
		}
	}
}