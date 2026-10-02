#include"Cpoint.h"

int main()
{
	Cpoint P,P1(10, 20);
    
	P.affiche();
	P1.affiche();
	P1.translate(2, 3);
	P1.affiche();
//P1.Cpoint(4);

   
    
	Cpoint pt1(10, 2),pt2(2, 3);
   // pt1.(3);
    //pt2.10 = pt1.10;
    pt1.Coincide(pt2);
	pt1.affiche();
    pt2.affiche();
    
	
   pt2.Coincide(pt1);

	return 0;
}
