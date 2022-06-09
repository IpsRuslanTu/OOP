#include "CTime.h"
#include <stdexcept>
#include <iostream>

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

CTime CTime::operator *(int const& x)const
{
	int result = m_time * x;

	if (result < 0)
	{
		result = result % (MAX_SECONDS + 1);
		if (result != 0)
		{
			result = MAX_SECONDS + 1 + result;
		}

		return CTime(result);
	}

	result = result > MAX_SECONDS ? (result % (MAX_SECONDS + 1)) : result;

	return CTime(result);
}

CTime operator *(int const& x, CTime const& time)
{
	return CTime(time * x);
}

CTime CTime::operator /(int i)const
{
	if (i == 0)
	{
		throw std::invalid_argument("You can't divide by zero");
	}

	int result;

	if (i < 0)
	{
		i = -i;
		result = m_time / i;
		result = -result;

		result = result % (MAX_SECONDS + 1);
		result = MAX_SECONDS + 1 + result;

		return CTime(result);
	}
	else {
		result = m_time / i;
	}

	return CTime(result);
}

int CTime::operator /(CTime const& time)const
{
	return m_time / time.m_time;
}

CTime& CTime::operator *=(int const& x)
{
	CTime temp = *this * x;
	this->m_time = temp.m_time;

	return *this;
}

CTime& CTime::operator /=(int const& x)
{
	CTime temp = *this / x;
	this->m_time = temp.m_time;

	return *this;
}

std::ostream& operator <<(std::ostream& ostream, CTime const& time)
{
	ostream << time.GetHours() << ":" << time.GetMinutes() << ":" << time.GetSeconds() << endl;

	return ostream;
}

std::istream& operator >>(istream& is, CTime& time)
{
	unsigned h;
	unsigned m;
	unsigned s;

	is >> h;
	is.ignore(1, ':');
	is >> m;
	is.ignore(1, ':');
	is >> s;

	CTime temp(h, m, s);

	time.m_time = temp.m_time;

	return is;
}

bool CTime::operator ==(const CTime& other)const
{
	return m_time == other.m_time;
}

bool CTime::operator !=(const CTime& other)const
{
	return m_time != other.m_time;
}

bool CTime::operator >(const CTime& other)const
{
	return m_time > other.m_time;
}

bool CTime::operator <(const CTime& other)const
{
	return m_time < other.m_time;
}

bool CTime::operator >=(const CTime& other)const
{
	return m_time >= other.m_time;
}

bool CTime::operator <=(const CTime& other)const
{
	return m_time <= other.m_time;
}