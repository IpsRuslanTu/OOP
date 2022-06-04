#pragma once
#include <stdexcept>

class CTime
{
public:
	CTime(unsigned hours, unsigned minutes, unsigned seconds = 0);

	CTime(unsigned timeStamp = 0);

	unsigned GetHours()const;

	unsigned GetMinutes()const;

	unsigned GetSeconds()const;

	CTime& operator++();       // Prefix increment operator.
	CTime operator++(int);     // Postfix increment operator.

	CTime& operator--();
	CTime operator--(int);

	CTime operator +(CTime const& time)const;
	CTime operator -(CTime const& time)const;

	CTime& operator +=(CTime const& time);
	CTime& operator -=(CTime const& time);

private:
	const int MAX_SECONDS = 86399;
	unsigned m_time;
};

