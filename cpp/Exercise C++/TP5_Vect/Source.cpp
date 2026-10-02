#include "Vecteur.h"

int main()
{
	int nb;
	double* t;
	cout << "saisir le nb de composantes: ";
	cin >> nb;
	t = new double[nb];

	for (int i = 0; i < nb; i++)
	{
		t[i] = 2*i;
	}

	CVecteur test(nb, t);
	test.Affiche();

	CVecteur res3 = test.Prod_Simpl(2);
	res3.Affiche();
	
	double res2 = 0.0;
	res2 = test.prod_scal(res3);
	cout << res2 << endl;

	
	CVecteur res = test.Somme(res3);
	res.Affiche();

	return 0;
}