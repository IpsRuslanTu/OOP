#include "CTime.h"
#include <stdexcept>

using namespace std;

CTime::CTime(unsigned hours, unsigned minutes, unsigned seconds)
	: m_time(hours * 3600 + minutes * 60 + seconds)
{
	if (hours > 23 || hours < 0 || minutes > 59 || minutes < 0 || seconds > 59 || seconds < 0)
		throw std::invalid_argument("Time is set incorrectly");
}

CTime::CTime(unsigned timeStamp)
	: m_time(timeStamp)
{
	if (timeStamp > 86399 || timeStamp < 0)
		throw std::invalid_argument("Time in seconds is set incorrectly");
}

unsigned CTime::GetHours()const
{
	return m_time / 3600;
}

unsigned CTime::GetMinutes()const
{
	return m_time % 3600 / 60;
}

unsigned CTime::GetSeconds()const
{
	return m_time % 60;
}

CTime& CTime::operator++()
{
	m_time = m_time != MAX_SECONDS ? ++m_time : 0;

	return *this;
}

CTime CTime::operator++(int)
{
	CTime temp = *this;
	m_time = m_time != MAX_SECONDS ? ++m_time : 0;

	return temp;
}

CTime& CTime::operator--()
{
	m_time = m_time != 0 ? --m_time : MAX_SECONDS;

	return *this;
}

CTime CTime::operator--(int)
{
	CTime temp = *this;
	m_time = m_time != 0 ? --m_time : MAX_SECONDS;

	return temp;
}

CTime CTime::operator +(CTime const& time)const
{
	unsigned temp = m_time + time.m_time;
	temp = temp > MAX_SECONDS ? (temp - MAX_SECONDS - 1) : temp;

	return CTime(temp);
}

CTime CTime::operator -(CTime const& time)const
{
	int temp = m_time - time.m_time;
	temp = temp < 0 ? (MAX_SECONDS + 1 + temp) : temp;

	return CTime(temp);
}

CTime& CTime::operator +=(CTime const& time)
{
	this->m_time += time.m_time;
	this->m_time = this->m_time > MAX_SECONDS ? (this->m_time - MAX_SECONDS - 1) : this->m_time;

	return *this;
}

CTime& CTime::operator -=(CTime const& time)
{
	int temp = this->m_time -= time.m_time;
	this->m_time = temp < 0 ? (MAX_SECONDS + 1 + temp) : this->m_time;

	return *this;
}