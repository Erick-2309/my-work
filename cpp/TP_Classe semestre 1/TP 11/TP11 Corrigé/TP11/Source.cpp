#include "CTab2D.h"

int main()
{
	CTab2D tab1(5,5,10);
	tab1.FillRand();
	cout << tab1<<endl;

	CTab2D tab2(5, 5);

	int nl = 5;
	int nc = 5;
	
	double**T;
	T = new double*[nl];
	for (int i = 0; i < nl; i++)
	{
		T[i] = new double[nc+2];
	}

	srand((unsigned)time(NULL));
	for (int i = 0; i < nl; i++)
	{
		for (int j = 0; j < nc; j++)
		{
			T[i][j] = (10 + (20 - 10)*(double)rand() / RAND_MAX);
		}
	}

	T[0][0] = nl;
	T[0][1] = nc;
	cout << endl;

	// Test à finaliser pour l'opérateur CTab2D operator*(double)
	//tab2 = T;
	cout << tab2<<endl;
	tab2.set(3, 3, 27);
	cout << tab2<<endl;
	cout << tab2[2][2]<<endl;
	cout << tab2(2, 2);
	cout << tab2 + tab1;
	tab2 += 1.5;
	cout << tab1*tab2 << endl;

}