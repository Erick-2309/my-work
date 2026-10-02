#pragma once //Evite qu'un fichier soit réinclu

#include"CSolution.h"

class CSol2 : public CSolution
{
	double m_x1;
	double m_x2;
public:
	CSol2(double, double, double discriminant);
	virtual void Affiche();
	CSol2();
};
