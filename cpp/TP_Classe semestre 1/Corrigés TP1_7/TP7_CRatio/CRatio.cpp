#include "CRatio.h"

CRatio::CRatio(int n, int d)
	:m_num(n), m_den(d)
{
}

CRatio::CRatio(const CRatio& R)
	:m_den(R.m_den),m_num(R.m_num)
{
}

CRatio CRatio::operator-()
{
	return CRatio(-m_num,m_den);
}

CRatio CRatio::operator++()
{
	m_num += m_den;
	return *this;
}

CRatio CRatio::operator=(const CRatio& R)
{
	m_num = R.m_num;
	m_den = R.m_den;
	return *this;
}

CRatio CRatio::operator+(const CRatio& R)
{
	CRatio Res;
	Res.m_num = m_num * R.m_den + R.m_num * m_den;
	Res.m_den = m_den * R.m_den;

	return Res;
	// Autrement
	// return CRatio(m_num*R.m_den+R.m_num*m_den,m_den*R.m_den);
}

CRatio CRatio::operator-(const CRatio& R)
{
	CRatio Res;
	Res.m_num = m_num * R.m_den - R.m_num * m_den;
	Res.m_den = m_den * R.m_den;
	
	return Res;
	// Autrement
	// return CRatio(m_num * R.m_den - R.m_num * m_den, m_den * R.m_den);
}

CRatio CRatio::operator*(const CRatio& R)
{
	CRatio Res;
	Res.m_num = m_num * R.m_num;
	Res.m_den = m_den * R.m_den;
	return Res;
	// Autrement
	// return CRatio(m_num * R.m_num,m_den*R.m_den);
}

CRatio CRatio::operator*(int a)
{
	return CRatio(a*m_num,m_den);
}

int CRatio::operator&()
{
	int sgn = m_num * m_den;
	if (sgn < 0)
	{
		return -1;
	}
	else if (sgn > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

CRatio::~CRatio()
{
}

CRatio operator*(int a,const CRatio&R)
{
	return CRatio(a*R.m_num,R.m_den);
}

ostream& operator<<(ostream&os, const CRatio&R)
{
	os << R.m_num << "/" << R.m_den<<endl;
	return os;
}

istream& operator>>(istream& is,CRatio& R)
{
	cout << "Numerateur : ";
	is >> R.m_num;
	cout << "Denominateur : ";
	is >> R.m_den;
	return is;
}
