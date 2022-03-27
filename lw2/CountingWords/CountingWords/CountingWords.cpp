#include <iostream>
#include <string>
#include <map>
#include <windows.h>
#include "FunctionsForMap.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    map <string, unsigned int> countWords;
    string str;
    cout << "Input string:" << endl;

    while (getline(cin, str))
    {
        countWords = AddAndCountWordsToMap(countWords, str);
    }
    PrintMap(countWords);
}