#include "CScdDgr.h"
#include"CSol0.h"
#include"CSol1.h"
#include"CSol2.h"

CScdDgr::CScdDgr():m_pa(0),m_pb(0),m_pc(0),m_pSol(NULL)
{
}

CScdDgr::CScdDgr(double a, double b, double c) : m_pa(a), m_pb(b), m_pc(c), m_pSol(NULL)
{
}

CScdDgr::~CScdDgr()
{
}

double CScdDgr::Discriminant()
{
	double d;
	d = pow(m_pb, 2) - 4 * m_pa * m_pc;
	return d;
}

void CScdDgr::Affiche()
{
	m_pSol->Affiche();
}

void CScdDgr::Solution()
{
	double D = Discriminant();
	if (D > 0)
	{
		m_pSol = new CSol2(m_pa,m_pb,D);
	}
	if (D == 0)
	{
		m_pSol = new CSol1(m_pa,m_pb);
	}
	if (D < 0)
	{
		m_pSol = new CSol0();
	}
}
