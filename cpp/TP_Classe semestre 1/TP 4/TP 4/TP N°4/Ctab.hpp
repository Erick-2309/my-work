#include<iostream>
using namespace std;

class Cptab
{
private:
    int m_N;
    double * m_ptab;
public:
    Cptab();
    Cptab(int);
    Cptab(int,double*);
    Cptab(const Cptab&);
    ~Cptab();
    friend ostream& operator<<(ostream&,const Cptab&);
    friend istream& operator>>(istream&,Cptab&);
    Cptab operator=(const Cptab&);
    void Random(int , int);
    double Moyenne();
    double Max();
    double Min();
    double Ect();
    void Swap(int , int);
    void Tri(bool);
};





