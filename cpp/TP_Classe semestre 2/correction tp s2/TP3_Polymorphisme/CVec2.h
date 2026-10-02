#pragma once
#include <iostream>
using namespace std;
class CVec2
{
private: 
	double m_x1, m_x2;
public:
	CVec2(double = 0.0, double = 0.0);
	~CVec2();
	virtual void aff();
};

