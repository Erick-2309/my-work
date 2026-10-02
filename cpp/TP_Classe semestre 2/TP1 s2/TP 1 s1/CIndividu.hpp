#pragma once
#include <iostream>
using namespace std;

class  CIndividu
{
protected:
    char * m_nom;
    int m_age;
public :
    CIndividu();
    CIndividu(char*,int);
    CIndividu(const CIndividu&);
    ~CIndividu();
    friend ostream& operator<<(ostream&, CIndividu&);
    friend istream& operator>>(istream&,CIndividu&);
    
};
