#pragma once
#include"CSolution.h"
#include<iostream>
using namespace std;

class CScdDgr : public CSolution
{
private:
	double m_pa;
	double m_pb;
	double m_pc;

	CSolution* m_pSol;

public:
	CScdDgr();
	CScdDgr(double, double, double);
	~CScdDgr();

	double Discriminant();
	void Affiche();
	void Solution();
};

