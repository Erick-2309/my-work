#include "Vecteur.h"

CVecteur::CVecteur(int n)
{
	m_nN = n;
	m_ptab = new double[m_nN];
	for (int i = 0; i < m_nN; i++)
	{
		m_ptab[i] = 0.0;
	}
}

CVecteur::~CVecteur()
{
	if (m_ptab != NULL)
	{
		delete[] m_ptab;
		m_ptab = NULL;
	}
}

CVecteur::CVecteur(int a, double* t)
{
	m_nN = a;
	m_ptab = new double[m_nN];
	for (int i = 0; i < m_nN; i++)
	{
		m_ptab[i] = t[i];
	}

}

void CVecteur::Affiche()
{
	cout << "Nombre de composantes: " << m_nN << endl;
	for (int i = 0; i < m_nN; i++)
	{
		cout << "case " << i + 1 << ": " << m_ptab[i] << endl;
	}
}

CVecteur::CVecteur(const CVecteur& V)
{
	m_nN = V.m_nN;
	m_ptab = new double[m_nN];
	for (int i = 0; i < m_nN; i++)
	{
		m_ptab[i] = V.m_ptab[i];
	}
}

double CVecteur::prod_scal(const CVecteur& V)
{
	double res = 0.0;
	for (int i = 0; i < m_nN; i++)
	{
		res += m_ptab[i] * V.m_ptab[i];
	}
	return res;
}

CVecteur CVecteur::Prod_Simpl(int lamda)
{
	CVecteur Res(m_nN);
	
	for (int i = 0; i < m_nN; i++)
	{
		Res.m_ptab[i] = m_ptab[i] * lamda;
	}

	return Res;
}

CVecteur CVecteur::Somme(const CVecteur& V)
{
	CVecteur Res(m_nN);

	for (int i = 0; i < m_nN; i++)
	{
		Res.m_ptab[i] = m_ptab[i] + V.m_ptab[i];
	}
	return Res;
}
