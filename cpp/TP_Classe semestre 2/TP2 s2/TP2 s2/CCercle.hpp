#ifndef CCercle_hpp
#define CCercle_hpp
#include <iostream>
#include "CPoint2D.hpp"
using namespace std;
#endif /* CCercle_hpp */

class CCercle :public CPoint2D
{
protected:
    int m_r;
public:
    CCercle();
    CCercle(int,int*);
    CCercle(const CCercle&);
    ~CCercle();
    friend ostream& operator<<(ostream&,CCercle&);
    friend istream& operator>>(istream&,CCercle&);
    void redimensionne(int);
};
