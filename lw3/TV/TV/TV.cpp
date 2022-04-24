#include <iostream>
#include <assert.h>
#include "CTVSet.h"
#include "CRemoteControl.h"

using namespace std;

void TestTVCreation()
{
	CTVSet tv;

	assert(tv.IsTurnedOn() == false);
	assert(tv.GetChannel() == 0);

	tv.TurnOn();
	assert(tv.IsTurnedOn() == true);
	assert(tv.GetChannel() == 1);

	tv.SelectChannel(100);
	assert(tv.GetChannel() == 1);
	tv.SelectChannel(5);
	assert(tv.GetChannel() == 5);

	tv.TurnOff();
	assert(tv.IsTurnedOn() == false);
	assert(tv.GetChannel() == 0);
	tv.SelectChannel(1);
	assert(tv.GetChannel() == 0);

	tv.TurnOn();
	assert(tv.GetChannel() == 5);

	cout << "TV creation test is ok\n";
}
void TestSelectPreviousChannel()
{
	CTVSet tv;
	tv.TurnOn();
	assert(tv.GetChannel() == 1);

	tv.SelectChannel(5);
	assert(tv.GetChannel() == 5);

	tv.SelectPreviousChannel();
	assert(tv.GetChannel() == 1);

	tv.SelectPreviousChannel();
	assert(tv.GetChannel() == 5);

	tv.SelectChannel(10);
	tv.SelectPreviousChannel();
	assert(tv.GetChannel() == 5);

	tv.SelectPreviousChannel();
	assert(tv.GetChannel() == 10);

	cout << "TV SelectPreviousChannel is ok\n";
}

int main()
{
	//TestTVCreation();
	//TestSelectPreviousChannel();

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