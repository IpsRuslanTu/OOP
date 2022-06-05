#include <iostream>
#include "CTime.h"

using namespace std;

int main()
{
    CTime time(2, 6, 8);
    CTime time1 = time;

    cout << time1.GetHours();

    return 0;
}