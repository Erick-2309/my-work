#include<iostream>
#include<math.h>
using namespace std;


int_least32_t methode_rectangle (double x,double pas,int bi,int bs)
{
	bi=0,bs=1;
	pas=0.1;
	x=0;
	double N;
	N=(bs-bi)/pas;
	for (int i=1;i<N;i++)
	{
		return sqrt(2-2*x*x);
		x+=pas;
	}
	return sqrt(2-2*x*x);
}

int main()
{
	int N;
	double x;
	int bi=0,bs=1;
	double pas=0.1;
	N=(bs-bi)/pas;
	cout<<"combien de point voulez vous utiliser pour evaluer la valeur approchée\n";
	//cin>>N;
	cout<<methode_rectangle (x,pas,bi,bs)<<endl;
    return 0;
}
