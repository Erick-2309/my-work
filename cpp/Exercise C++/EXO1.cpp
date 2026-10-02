//resoud une equation de degré 2
#include<iostream>
using namespace std;
#include<math.h>
 
 
 int Discriminant(int a, int b, int c) {
	 return (b * b - 4 * a * c);
}

int Affiche_racine(int a, int b, int c) 
{
	float D = Discriminant( a,b,c);
	float  X0,X1, X2;
	X0 = (-b / 2 * a);
	X1 = (-b - sqrt(D)) /( 2 * a);
	X2 = (-b + sqrt(D)) / (2 * a);
	if (D >= 0)
	{
		if (D == 0)
		{
			cout << "la racinedouble double vaut:" <<X0 << endl;
		}
		else if(D>0)
		{
			cout << "les racines relles sont:" << X1 << "et" << X2 << endl;
		}
	}
	else
		cout << "les racines complexes sont:" << (-b / (2 * a)) << "+i" << (sqrt(-D) /( 2 * a)) <<  " et " << (-b / (2 * a)) << "-i" << (sqrt(-D) /( 2 * a)) << endl;	
	return 0;
}

int main() 
{
	int a,b,c;
	cout << "coefX2" << endl;
	cin >> a;
	cout << "coefX" << endl;
	cin >> b;
	cout << "coefX0" << endl;
	cin >> c;
	cout << Affiche_racine(a, b, c);
	return 0;

}
