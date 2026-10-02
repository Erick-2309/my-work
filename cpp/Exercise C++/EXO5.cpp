#include<iostream>
using namespace std;

bool premier_nbr(int N, int& div)
{

	bool prem = true;
	int i = 2;
	while ((i < N) && (prem == true))
	{
		if (N % i == 0)
		{
			prem = false;
			div = i;
		}
		i++;
	}
	return prem;
}
int main()
{
	int nbr=1;
	cout << "entrez un nombre" << endl;
	cin >> nbr;
	int d =0;
	if (premier_nbr(nbr ,d) == true)
	{
		cout << "premier" << endl;
		cout << 1 << endl;
	}
	else
	{
		cout << "pas premier" << endl;
		cout << d << endl;
	}
	return 0;
}