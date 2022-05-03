#include "CTVSet.h"
#include <iostream>

int CTVSet::GetChannel() const
{
	if (m_isOn == false)
	{
		//может привети к ошибкам, по устловию 0 должно быть равно состояние канала
		//может так получится что будет добавляться новый функционал, который тоже
		//операется на это условие
		return 0;
	}
	return m_channel;
}

//лучше добавить возможно сообщить пользователю о проблеме
void CTVSet::TurnOn()
{
	m_isOn = true;
}

void CTVSet::TurnOff()
{

	m_isOn = false;
}

bool CTVSet::IsTurnedOn() const
{
	return m_isOn;
}

bool CTVSet::SelectChannel(int channel)
{
	if (m_isOn && isInRange(channel))
	{
		m_prevChannel = m_channel;
		m_channel = channel;

		return true;
	}

	return false;
}

void CTVSet::SelectPreviousChannel()
{
	if (m_isOn)
	{
		std::swap(m_channel, m_prevChannel);
	}
}

void CTVSet::SetChannelName(int channel, std::string name)
{
	if (!m_isOn)
	{
		return;
	}

	if (!isInRange(channel))
	{
		return;
	}

	for (auto it = m_namedChannels.begin(); it != m_namedChannels.end();)
	{
		if (it->first == channel || it->second == name)
		{
			it = m_namedChannels.erase(it);
		}
		else
		{
			++it;
		}
	}

	m_namedChannels.insert(make_pair(channel, name));
}

std::map<int, std::string> CTVSet::GetNamedChannels() const
{
	return m_namedChannels;
}

std::string CTVSet::GetChannelName(int channel)
{
	if (!isInRange(channel))
	{
		return "You can use only channels from 1 to 99";
	}

	std::map<int, std::string>::iterator it;
	it = m_namedChannels.find(channel);

	return it != m_namedChannels.end()
		? it->second
		: "Channel " + std::to_string(channel) + " hasn't name\n";
}

int CTVSet::GetChannelByName(const std::string name) const
{
	for (auto it = m_namedChannels.begin(); it != m_namedChannels.end();)
	{
		if (it->second == name)
		{
			return it->first;
		}
		else
		{
			++it;
		}
	}

	return 0;
}

int CTVSet::DeleteChannelName(std::string name)
{
	for (auto it = m_namedChannels.begin(); it != m_namedChannels.end();)
	{
		if (it->second == name)
		{
			int channel = it->first;
			m_namedChannels.erase(it);

			return channel;
		}
		else
		{
			++it;
		}
	}

	return 0;
}

bool CTVSet::isInRange(int channel)
{
	return channel >= 1 && channel <= 99 ? true : false;
}
