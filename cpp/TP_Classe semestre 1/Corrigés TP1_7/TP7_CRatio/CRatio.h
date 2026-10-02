#pragma once
#include <iostream>
using namespace std;
class CRatio
{
private:
	int m_num;
	int m_den;
public:
	CRatio(int=0, int=1);
	CRatio(const CRatio&);
	~CRatio();

	CRatio operator-();
	CRatio operator++();
	CRatio operator=(const CRatio&);
	CRatio operator+(const CRatio&);
	CRatio operator-(const CRatio&);
	CRatio operator*(const CRatio&);
	CRatio operator*(int);
	friend CRatio operator*(int a,const CRatio&);
	friend ostream& operator<<(ostream&,const CRatio&);
	friend istream& operator>>(istream&,CRatio&);
	int operator&();

};

