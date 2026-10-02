#include <iostream>
#include <stdlib.h>
using namespace std;

class CSignal
{
private:
    int m_N;
    double*m_ptab;
public:
    //CSignal();
    CSignal(int N=0);
    CSignal(int,double*);
    CSignal(const CSignal&);
    
    void FillRand();
    
    friend ostream&operator <<(ostream&, const CSignal&);
    friend istream&operator>>(istream&, CSignal&);
    
    CSignal operator=(const CSignal&);
    
    void multiplie(const CSignal&, double );
    
    double operator [] (int);
    
    CSignal operator+(const CSignal&);
    
    CSignal operator+=(const CSignal&);
    
    CSignal operator+=(double);
    
    double operator*(const CSignal&);
    
    CSignal operator*(double);
    
    friend CSignal operator*(double, const CSignal&);
    
   // CSignal operator*=(double);
    
    double Moyenne();
    double Variance();
    double Min();
    double Max();
    void Tri();
};

