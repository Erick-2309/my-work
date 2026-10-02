#include<iostream>
using namespace std;
/*
double ordonee(double p)
{
	 return( 9 * p * p + 6 * p - 1);
}
int main()
{
	
	double p = 0;
	
	for (p = -5; p <5; p += 0.1)
	{
		cout << ordonee(p)<<endl;
	}
	return 0;
}
*/

void  methode_rectangle (int x,pas,int bi,int bs)
{
	int bi=0,bs=1;
	double pas=0.1;
	int x;
	x=bi;
	double N;
	N=(bs-bi)/pas;
	for (int i=0;i<N;i++)
	{
		return sqr(2-2x*x);
		x+=pas;
	}
}

int main()
	{
		int N;
		int x;
		int bi=0;
		int bs=1;
		double pas=0.1;
		cout<<"combien de point voulez vous utiliser pour evaluer la valeur approchée\n";
		cin>>N;
		cout<<methode_rectangle (x,pas,bi,bs)<<endl;
	}
