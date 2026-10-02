#pragma once
#ifndef CPoint2D_hpp
#define CPoint2D_hpp
#endif /* CPoint2D_hpp */
#include <iostream>
using namespace std;

class CPoint2D
{
protected:
    int* m_pcoord;
public:
    CPoint2D();
    //CPoint2D(int,int);
    CPoint2D(int*);
    CPoint2D(const CPoint2D&);
    ~CPoint2D();
    friend ostream&operator<<(ostream&,const CPoint2D&);
    friend istream&operator>>(istream&,CPoint2D&);
    void translate(int,int);
};

