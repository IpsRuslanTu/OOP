#include <iostream>
#include "CTime.h"

using namespace std;

int main()
{
    CTime time(2, 6, 8);
    cout << time.GetHours() << endl;
    cout << time.GetMinutes() << endl;
    cout << time.GetSeconds() << endl;

    return 0;
}