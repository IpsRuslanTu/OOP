#pragma once

class CTVSet
{
public:
	int GetChannel()const;
	void TurnOn();
	void TurnOff();
	bool IsTurnedOn()const;
	void SelectChannel(int channel);
	void SelectPreviousChannel();

private:
	int m_channel = 1;
	int m_prevChannel = m_channel;
	bool m_isOn = false;
};

