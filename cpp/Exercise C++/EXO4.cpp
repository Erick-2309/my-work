#include<iostream>
using namespace std;

int est_premier_nbr(int N )//;int& ind)
{
	bool prem = true; 
	int i=2;
	
	//while((i<N) && (prem == true))
		for(int i=2;i<N;i++)
		{
		   if (N % i == 0)
		   {
			  prem = false;
			  //ind =i;
		   }
		  // i++;
		}
	return prem;
}

int  main()
{
	int nbr=0;
	//int c=0;
	cout << "entrez un nombre" << endl;
	cin >> nbr;
	if (est_premier_nbr(nbr) == true)
	{
		cout <<nbr<<" est premier" << endl;
		//cout<<1<<endl;
	}
	else
	{
		cout <<nbr<<" n'est pas premier" << endl;
		//cout<<c<<endl;
	}
	return 0;
}