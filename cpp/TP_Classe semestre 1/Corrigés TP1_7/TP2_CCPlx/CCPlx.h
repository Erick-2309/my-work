#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class CCPlx
{
private :
	double m_Re;
	double m_Im;

public :

	CCPlx();
	~CCPlx();
	CCPlx(int Re, int Im);
	void Affiche();
	CCPlx(const CCPlx&);
	double Module();
	CCPlx Addition(const CCPlx& C);
	CCPlx Multiplication(const CCPlx& C);
};

