#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

vector<float> ReadingArrayFromInputStream();

vector<float> MultiplyNegativeValuesInArray(const vector<float> inputArr, const float operand);

int main()
{
    vector<float> arrOfFloat = ReadingArrayFromInputStream();

    if (arrOfFloat.empty())
    {
        cout << "Check the input data. Incorrect input";
        return 1;
    }

    float arrMax = *max_element(arrOfFloat.begin(), arrOfFloat.end());
    float arrMin = *min_element(arrOfFloat.begin(), arrOfFloat.end());
    float multiplier = arrMax * arrMin;

    vector<float> changedArrOfFloat = MultiplyNegativeValuesInArray(arrOfFloat, multiplier);

    sort(changedArrOfFloat.begin(), changedArrOfFloat.end());

    cout << "Sorted array, were all negative values multiplied by the maximum and minimum " << 
        "elements of this array:" << endl;
    copy(changedArrOfFloat.begin(), changedArrOfFloat.end(),
        ostream_iterator<float>(cout << fixed << setprecision(3), " "));

    cout << endl;
}

vector<float> ReadingArrayFromInputStream()
{
    cout << "Enter a float type number separated by a space:\n";
    string temp;
    getline(cin, temp);
    stringstream ss;
    ss.str(temp);

    vector<float> arrOfFloat;
    float num;
    while (ss >> num)
    {
        arrOfFloat.push_back(num);
    }
    return arrOfFloat;
}

vector<float> MultiplyNegativeValuesInArray(const vector<float> inputArr, const float operand)
{
    vector<float> newArray(inputArr.size());
    for (int i = 0; i < inputArr.size(); ++i)
    {
        newArray[i] = (inputArr[i] < 0) ? (inputArr[i] * operand) : (inputArr[i]);
    }
    return newArray;
}