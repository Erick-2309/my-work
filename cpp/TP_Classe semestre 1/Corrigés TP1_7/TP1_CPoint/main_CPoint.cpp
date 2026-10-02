#include <iostream>
using namespace std;
#include "CPoint.h"

int main() 
{

	CPoint P; // Utilisation du constructeur sans paramètres
	P.Affiche();

	CPoint P1(5, 10); // Utilisation du constructeur avec paramètres
	P1.Affiche();

	CPoint pt1(5, 2);
	CPoint pt2(2, 3);

	pt1.Affiche();
	pt2.Affiche();

	pt1.Translate(2, 5);
	cout << "Nouvelle position de pt1 : ";
	pt1.Affiche();

	CPoint P3(3); // Utilisation du contructeur inline
	P3.Affiche();

	// Utilisation de la fonction coincide
	bool test = pt1.Coincide(pt2);

	if (test)
	{
		cout << "Les points 1 et 2 coincident :" << endl;
	}
	else
	{
		cout << "Les points 1 et 2 ne coincident pas" << endl;
	}
	return 0;

}