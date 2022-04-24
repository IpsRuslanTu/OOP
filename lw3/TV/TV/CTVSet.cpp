#include "CTVSet.h"
#include <algorithm>

int CTVSet::GetChannel()const
{
	if (m_isOn == false)
	{
		//����� ������� � �������, �� �������� 0 ������ ���� ����� ��������� ������
		//����� ��� ��������� ��� ����� ����������� ����� ����������, ������� ����
		//��������� �� ��� �������
		return 0;
	}
	return m_channel;
}

//����� �������� �������� �������� ������������ � ��������
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