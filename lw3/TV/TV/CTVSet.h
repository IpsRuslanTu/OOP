#pragma once
#include <map>
#include <string>

class CTVSet
{
public:
	void TurnOn();
	void TurnOff();
	int GetChannel() const;
	bool IsTurnedOn() const;
	bool SelectChannel(int channel);
	bool SelectChannel(std::string channel);
	void SelectPreviousChannel();
	void SetChannelName(int channel, std::string name);
	std::map<int, std::string> GetNamedChannels() const;
	std::string GetChannelName(int channel);
	int GetChannelByName(const std::string name) const;
	int DeleteChannelName(std::string name);

private:
	int m_channel = 1;
	int m_prevChannel = 1;
	bool m_isOn = false;
	std::map<int, std::string> m_namedChannels;

	bool isInRange(int channel);
};