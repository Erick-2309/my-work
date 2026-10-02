#ifndef CEllipse_hpp
#define CEllipse_hpp

#include <iostream>
#include "CCercle.hpp"
#endif /* CEllipse_hpp */

class CEllipse :public CCercle
{
protected:
    int m_pr;
public:
    CEllipse();
    CEllipse(int,int,int*);
    CEllipse(const CEllipse&);
    ~CEllipse();
    friend ostream& operator<<(ostream&,CEllipse&);
    friend istream& operator>>(istream&,CEllipse&);
    void redimensionne(int);
};
