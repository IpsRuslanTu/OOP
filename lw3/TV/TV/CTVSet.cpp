#include "CTVSet.h"
#include <algorithm>

int CTVSet::GetChannel()const
{
	if (m_isOn == false)
	{
		return 0;
	}
	return m_channel;
}

void CTVSet::TurnOn()
{
	if (m_isOn == false)
	{
		m_isOn = true;
	}
}

void CTVSet::TurnOff()
{
	if (m_isOn == true)
	{
		m_isOn = false;
	}
}

bool CTVSet::IsTurnedOn()const
{
	return m_isOn;
}

void CTVSet::SelectChannel(int channel)
{
	if (m_isOn)
	{
		if (channel >= 1 && channel <= 99)
		{
			m_channel = channel;
		}
	}
}

void CTVSet::SelectPreviousChannel()
{
	if (m_isOn)
	{
		std::swap(m_channel, m_prevChannel);
	}
}