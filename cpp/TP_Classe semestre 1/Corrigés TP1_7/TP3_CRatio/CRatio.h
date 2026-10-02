#pragma once
#include <iostream>
using namespace std;

class CRatio
{
private :

	int m_nNum;
	int m_nDeno;

public :
	CRatio(int nNum = 0, int nDeno = 1);
	~CRatio();
	CRatio(const CRatio& S);
	void Affiche();
	CRatio Oppose();
	int Signe();
	CRatio Incremente();
	CRatio Somme(const CRatio& S);
	CRatio Difference(const CRatio& D);
	CRatio ProduitRatio(const CRatio& P);
	CRatio ProduitScal(int ProScal);
};

