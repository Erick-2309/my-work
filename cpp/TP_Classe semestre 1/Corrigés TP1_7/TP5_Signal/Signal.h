#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
class CSignal
{
	int m_nN;
	double* m_ptab;
public:
	CSignal(int=5);
	CSignal(int, double*);
	CSignal(const CSignal&);
	~CSignal();
	void Random(int,int);
	friend ostream& operator <<(ostream&, CSignal&);
	CSignal operator = (const CSignal&);
    CSignal operator = (double*);
    double operator[](int);
    CSignal operator*(double);
    CSignal operator+(const CSignal&);
    CSignal operator+=(const CSignal&);
    CSignal operator+=(double);
    CSignal operator*(const CSignal&);
    CSignal operator*(double);
    friend CSignal operator*(double, const CSignal&);   // operator friend car la première opérande n'est pas de type classe, c'est un double
	void Permute(int, int);
	void Tri_Sel();
	void Tri_Bulle();
	void Tri_Insert();
};

