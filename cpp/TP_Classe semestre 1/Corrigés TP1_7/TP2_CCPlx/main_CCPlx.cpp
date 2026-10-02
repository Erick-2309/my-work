#include <iostream>
#include "CCPlx.h"
using namespace std;

int main()
{
	CCPlx P(3, 4);
	P.Affiche();

	CCPlx P1(2, 2);
	P1.Affiche();

	CCPlx Somme = P.Addition(P1);
	cout << "Le resultat de l'addition est : " << endl;
	Somme.Affiche();

	CCPlx Resultat = P.Multiplication(P1);
	cout << "Le resultat de la multiplication est : " << endl;
	Resultat.Affiche();


	cout << "Le module de P1 = " << P1.Module() << endl;

	return 0;
}

