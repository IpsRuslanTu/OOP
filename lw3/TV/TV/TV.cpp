#include <iostream>
#include <assert.h>
#include "CTVSet.h"
#include "CRemoteControl.h"

using namespace std;

void TestTV()
{
	CTVSet tv;
	tv.TurnOn();
	
	tv.SetChannelName(2, "Hello");
	assert(tv.GetChannelByName("Hello") == 2);

	cout << "TV SelectPreviousChannel is ok\n";
}

int main()
{
	TestTV();

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