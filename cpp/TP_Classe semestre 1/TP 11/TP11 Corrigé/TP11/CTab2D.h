#pragma once
using namespace std;
#include<iostream>
#include<time.h>

class CTab2D
{
public:
	void Alloc(int, int);
	void free();
	void Init(int l = 1, int c = 1, double val = 0.0);
	CTab2D(int l=1, int c=1, double val=0.0);
	CTab2D(const CTab2D &);
	void FillRand();
	friend ostream& operator <<(ostream &, const CTab2D &);
	CTab2D operator=(double**);
	CTab2D operator=(const CTab2D &);
	void set(int, int, double);
	double *operator[](int);
	double operator()(int, int);
	CTab2D operator+(const CTab2D&);
	CTab2D operator+=(const CTab2D &);
	CTab2D operator+=(double);
	CTab2D operator*(double);
	friend CTab2D operator*(double, const CTab2D&);
	CTab2D operator*(const CTab2D&);
	~CTab2D();
private:
	int m_nL;
	int m_nC;
	double **m_pTab;
};

