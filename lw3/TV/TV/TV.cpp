#include <iostream>
#include "CTVSet.h"
#include "stdafx.h"
#include <assert.h>

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
	tv.SelectPreviousChannel();
	assert(tv.GetChannel() == 1);

	tv.SelectChannel(5);
	tv.SelectPreviousChannel();
	assert(tv.GetChannel() == 1);

	tv.SelectChannel(6);
	tv.SelectPreviousChannel();
	assert(tv.GetChannel() == 5);

	tv.TurnOff();
	assert(tv.GetChannel() == 0);

	tv.TurnOn();
	tv.SelectPreviousChannel();
	assert(tv.GetChannel() == 6);

	cout << "TV SelectPreviousChannel is ok\n";
}

int main()
{
	//TestTVCreation();
	TestSelectPreviousChannel();

	CTVSet tv;

	cout << "You brought new TV at home and plugged it into the outlet." << endl;
	cout << "You picked up the remote control and can use your TV." << endl;

	int command;

	do
	{
		cout << "1 - Turn on TV" << endl;
		cout << "2 - Turn off TV" << endl;
		cout << "3 - Switch channel" << endl;
		cout << "4 - Turn on the last channel" << endl;
		cout << "5 - Exit from program" << endl;
		cout << "Choose an action: ";
		cin >> command;
		cout << endl;

		switch (command)
		{
		case 1:
			tv.TurnOn();
			break;
		case 2:
			tv.TurnOff();
			break;
		case 3:
			int channel;
			cout << "You can switch channel from 1 to 99" << endl;
			cin >> channel;
			tv.SelectChannel(channel);
			cout << endl;
			break;
		case 4:
			tv.SelectPreviousChannel();
			break;
		case 5:
			break;
		default:
			cout << "Invalid command" << endl;
			break;
		}

		string statusTV = tv.IsTurnedOn() ? "ON" : "OFF";
		cout << "TV is " << statusTV << ". Channel is " << tv.GetChannel() << endl;

	} while (command != 5);
}