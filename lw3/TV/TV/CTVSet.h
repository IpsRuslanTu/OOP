#pragma once

class CTVSet
{
public:
	int GetChannel()const;
	void TurnOn();
	void TurnOff();
	bool IsTurnedOn()const;
	bool SelectChannel(int channel);
	void SelectPreviousChannel();

private:
	int m_channel = 1;
	int m_prevChannel = 1;
	bool m_isOn = false;
};