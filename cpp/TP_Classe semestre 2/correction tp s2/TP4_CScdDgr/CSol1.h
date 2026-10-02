#pragma once
#include"CSolution.h"

class CSol1 : public CSolution
{
	double m_x1;

public:
	CSol1(double a, double b);
	virtual void Affiche();
	~CSol1();
};
