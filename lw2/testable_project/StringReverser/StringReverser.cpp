// StringReverser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Reverse.h"

using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        cout << Reverse(line) << endl;
    }
}