#include "CTVSet.h"
#include <algorithm>

int CTVSet::GetChannel()const
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

bool CTVSet::IsTurnedOn()const
{
	return m_isOn;
}

bool CTVSet::SelectChannel(int channel)
{
	if (m_isOn && (channel >= 1 && channel <= 99))
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