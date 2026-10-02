#pragma once
#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
using namespace std;

class CVect
{
private:
    double *m_vect;
    int m_N;

public:
    CVect(int);
    CVect(double* =NULL, int=0);
    CVect(const CVect &);
    ~CVect();
    void remplir();
    void Ecrit(char *);
    friend ostream &operator<<(ostream &, const CVect &);
    void Lit(char *);
    void Ecrit_Bin(char *);
    void Lit_Bin(char *);
    void Add_Flux(char *);
};
