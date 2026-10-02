#include <iostream>
using namespace std;

/*int main_EXO1()
{
	int a=0, b=0;
	cout <<"saisir a"<< endl;
	cin >> a;
	cout << "saisir b" << endl;
	cin >> b;
		if(a > b)
		{
			if (a % b == 0)
			{
				cout << "b divise a" << endl;
			}
			else
				cout << "b ne divise pas a" << endl;
		}
		else
		{
			if (b % a == 0)
			{
				cout << "a divise b" << endl;
			}
			else
				cout << "a divise b" << endl;
		}
	return 0;
}


int mainEXO2()
{
	int x = 0;
	cout << "saisir x" << endl;
	cin >> x;
	if (x > 0)
	{
		cout << "x est strictement positif" << endl;
	}
	else if (x >= 0)
		{
			cout << "x est  positif" << endl;
		}

	else
		cout << "x est strictement negatif" << endl;

	return 0;
}

	switch (x);


	int calul_factoriel(int a)
	{
		int p = 1;
		for (int i = 0; i <=a-1 ; i++)
		{
			p *=(a-i);
		}
		return p;
	}
	int main()
	{
		int x = 0;
		cout << "saisir x" << endl;
		cin >> x;
		cout << calul_factoriel(x) <<endl;
		return 0;
	}
	*/

/*
int main()
{
	int L;
	cout << "nombre de ligne:" << endl;
	cin >> L;
	int i;
	for(i=0;i<=L;i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
*/
int main()
{
	int L;
	cout << "nombre de ligne:" << endl;
	cin >> L;
	for (int i = 0; i <= L; i++)
	{
		for (int j = 0; j <= L - i; j++)
		{
			cout << " ";
		}
		for (int k = 0; k <= 2 * i; k++)
		{
			cout << "*";
		}
		cout << endl;
	}

	return 0;
}
