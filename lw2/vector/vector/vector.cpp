#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "WorkWithVector.h"

using namespace std;

int main() {
	string buffer = GetStringFromUser();
	vector<float> arrOfFloat = GetFloatVectorFromString(buffer);

	if (arrOfFloat.empty()) {
		cout << "Check the input data. Incorrect input";
		return 1;
	}

	float multiplier = MultiplyMaxAndMinElementsOfVector(arrOfFloat);

	vector<float> changedArrOfFloat = MultiplyNegativeValuesInVector(arrOfFloat, multiplier);

	sort(changedArrOfFloat.begin(), changedArrOfFloat.end());

	cout << "\nSorted array, were all negative values multiplied by the maximum and minimum "
		 << "elements of this array:" << endl;

	copy(changedArrOfFloat.begin(), changedArrOfFloat.end(),
		ostream_iterator<float>(cout << fixed << setprecision(3), " "));

	cout << endl;
}