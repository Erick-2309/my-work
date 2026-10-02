#include "CRatio.h"

CRatio::CRatio(int nNum, int nDeno)
{
	m_nNum = nNum;
	m_nDeno = nDeno;

	cout << "Passage dans le constructeur par defaut" << endl;
}

CRatio::~CRatio()
{
	cout << "Passage dans le destructeur" << endl;
}

CRatio::CRatio(const CRatio& S)
{
	m_nNum = S.m_nNum;
	m_nDeno = S.m_nDeno;

	cout << "Passage dans le constructeur copie" << endl;
}

void CRatio::Affiche()
{
	cout << "Le nombre rationnel est : " << endl;
	cout << m_nNum << "/" << m_nDeno << endl;
}

CRatio CRatio::Oppose()
{
	return CRatio( -m_nNum, m_nDeno);
}

int CRatio::Signe()
{
	int signe = m_nNum * m_nDeno;

	if (signe > 0) 
	{
		return 1;
	}
	else if (signe < 0) 
	{
		return -1;
	}
	else 
	{
		return 0;
	}
}

CRatio CRatio::Incremente()
{
	return CRatio(m_nNum + m_nDeno, m_nDeno);
}

CRatio CRatio::Somme(const CRatio& R)
{
	int nNum = m_nNum * R.m_nDeno + R.m_nNum * m_nDeno;
	int nDeno = m_nDeno * R.m_nDeno;
	return CRatio(nNum, nDeno);
}

CRatio CRatio::Difference(const CRatio& D)
{
	int nNum = m_nNum * D.m_nDeno - D.m_nNum * m_nDeno;
	int nDeno = m_nDeno * D.m_nDeno;
	return CRatio(nNum, nDeno);
}

CRatio CRatio::ProduitRatio(const CRatio& P)
{
	m_nNum = m_nNum * P.m_nNum;
	m_nDeno = m_nDeno * P.m_nDeno;
	return CRatio(m_nNum, m_nDeno);
}

CRatio CRatio::ProduitScal(int ProScal)
{
	return CRatio(m_nNum * ProScal, m_nDeno);
}


