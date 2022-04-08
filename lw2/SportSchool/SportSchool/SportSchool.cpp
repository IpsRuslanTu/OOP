#include <iostream>
#include <algorithm>
#include <set>
#include "functions.h"

using namespace std;

int main(int argc, char* argv[])
{
    set<string> setSchool;

    for (int i = 1; i < argc; ++i)
    {
        // кажется можно сделать чуть оптимальнее используя один set
        set<string> setSection = GetSetFromFile(argv[i]);
        setSchool.insert(setSection.begin(), setSection.end());
    }
    
    cout << "School list:\n\n";
    copy(setSchool.begin(), setSchool.end(), ostream_iterator<string>(cout, "\n"));
}