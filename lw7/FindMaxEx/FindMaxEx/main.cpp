#include "stdafx.h"
#include "FindMaxEx.h"

using namespace std;

int main()
{
	std::vector<Sportsman> arrSportsmen =
	{
		{"Ivan Ivanov", 172, 72},
		{"Petr Petrov", 167, 73},
		{"Sidor Sidorov", 168, 68},
	};

	Sportsman sportsmen;

	FindMax(arrSportsmen, sportsmen, ComparatorHeight);

	cout << "Sportsman " << sportsmen.name << " has max height "
		<< sportsmen.height << "cm." << endl;

	FindMax(arrSportsmen, sportsmen, ComparatorWeight);

	cout << "Sportsman " << sportsmen.name << " has max weight "
		<< sportsmen.weight << "kg." << endl;
}