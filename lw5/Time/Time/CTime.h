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

	CTime operator *(int const& x)const;

	CTime operator /(int i) const;
	int operator /(CTime const& time)const;

	CTime& operator *=(int const& x);
	CTime& operator /=(int const& x);

	friend std::istream& operator >>(std::istream& is, CTime& time);

	bool operator ==(const CTime& other)const;
	bool operator !=(const CTime& other)const;

	bool operator >(const CTime& other)const;
	bool operator <(const CTime& other)const;

	bool operator >=(const CTime& other)const;
	bool operator <=(const CTime& other)const;

private:
	const int MAX_SECONDS = 86399;
	unsigned m_time;
};

CTime operator *(int const& x, CTime const& time);

std::ostream& operator <<(std::ostream& ostream, CTime const& time);