#include "Signal.h"


int main(void)
{
	CSignal A;  //test constructeur par def
	int taille = 2;
	double *p_tab;
	p_tab = new double[taille];
	p_tab[0] = 1;
	p_tab[1] = 4;

	CSignal B(taille, p_tab);  //test contructeur avec para
	cout << B;
    
    A.Random(0,1);
    cout << A;
    
    CSignal C;
    C = A;
    cout << C;
    
    C = A + b;
    cout << C;
    
    C = B * 3.0;
    cout << C;

    C = 2.0 * B;
    cout << C;
    
    C = A + B;
    cout << C;
    
    
	B.Permute(1, 0);  //test de permute
	cout << B;
	CSignal C1(6);
	C1.Random(0,1);
	cout << C;
	//C1.Tri_Sel();		//test de tri par selection
	//C1.Tri_Bulle();	//test de tri à bulle
	//C1.Tri_Insert();   //test de tri par insertion
	cout << C1;
    
	return 0;
}
