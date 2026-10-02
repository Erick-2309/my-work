#ifndef __INC_VECT
#define __INC_VECT

#include <iostream.h>
#include <fstream.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

class CVect
{
	int m_n;
	double *m_pdon;
public:
	CVect(int = 1);
	CVect(const CVect&);
	~CVect();
	void Remplir();
	friend ostream& operator <<(ostream&,const CVect&);
	void Ecrit(char*);
	void Lit(char*);
	void Lit_Bin(char*);
	void Ecrit_Bin(char*);
	void Add_Flux(char*);
};

#endif __INC_VECT
