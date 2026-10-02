#pragma once
#include <iostream>
using namespace std;

class CVecteur
{
private:
	int m_nN;
	double* m_ptab;
public:
	CVecteur(int =5);
	~CVecteur();
	CVecteur(int, double*);
	void Affiche();
	CVecteur(const CVecteur&);
	double prod_scal(const CVecteur& );
	CVecteur Prod_Simpl(int );
	CVecteur Somme(const CVecteur&a);


};

