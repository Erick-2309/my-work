#pragma once
#include <iostream>
#include "CIndividu.hpp"
using namespace std;

class CEleve : public CIndividu
{
    double *m_note;
    int m_N;

public:
    CEleve();
    CEleve(char *, int, double *, int);
    CEleve(const CEleve &);
    ~CEleve();
    friend ostream& operator<<(ostream&,CEleve&);
    friend istream& operator>>(istream&,CEleve&);
};
