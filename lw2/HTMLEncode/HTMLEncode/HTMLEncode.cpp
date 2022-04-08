#include <iostream>
#include <string>
#include "functions.h"

using namespace std;

int main()
{
    string line, encodingLine;

	cout << "Input strings for HTML-code:\n";
	while (getline(cin, line))
    {
		encodingLine = HTMLEncode(line);
		cout << encodingLine << endl;
    }
}