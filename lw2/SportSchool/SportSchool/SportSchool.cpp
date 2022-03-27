#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

set<string> GetSetFromFile(string inputFile)
{
    set<string> setSection;
    string student;
    ifstream input(inputFile);
    if (input.is_open())
    {
        while (input >> student)
        {
            setSection.insert(student);
        }
    }
    return setSection;
}

int main(int argc, char* argv[])
{
    set<string> setSchool;

    for (int i = 1; i < argc; ++i)
    {
        set<string> setSection = GetSetFromFile(argv[i]);
        setSchool.insert(setSection.begin(), setSection.end());
    }
    
    copy(setSchool.begin(), setSchool.end(), ostream_iterator<string>(cout, "\n"));
}