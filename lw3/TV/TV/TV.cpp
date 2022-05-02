#include <iostream>
#include <assert.h>
#include "CTVSet.h"
#include "CRemoteControl.h"

using namespace std;

int main()
{
	CTVSet tv;
	CRemoteControl remoteControl(tv, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!remoteControl.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}
	return 0;

}