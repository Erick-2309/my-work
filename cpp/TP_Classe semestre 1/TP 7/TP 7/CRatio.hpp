#include <istream>
using namespace std;
/*
class CRatio
{
private:
    int m_num;
    int m_den;
public:
    CRatio(double = 0.0, double = 0.0);
    ~CRatio();
    CRatio operator - ();
    int operator & ();
    CRatio operator ++ ();
    CRatio operator = (const CRatio&);
    CRatio operator + (const CRatio&);
    CRatio operator - (const CRatio&);
    CRatio operator * (const CRatio&);
    CRatio operator * (int);
    friend CRatio operator * (int, const CRatio&);
    friend ostream& operator << (ostream& cout, const CRatio& R);
    friend istream& operator >> (istream& cin, CRatio& R);
};*/


class CRatio
{
private:
    double* m_num;
    double* m_den;
public:
    CRatio(double=0.0, double=1.0);
    //CRatio();
    ~CRatio();
    
    CRatio operator-();
    int  operator&();
    CRatio operator ++();
    CRatio operator=(const CRatio&);
    CRatio operator + (const CRatio&);
    CRatio operator -= (const CRatio&);
    CRatio operator - (const CRatio&);
    CRatio operator * (const CRatio&);
    CRatio operator * (int);
    friend CRatio operator * (int,  CRatio&);
    friend ostream& operator << (ostream& cout, const CRatio& );
    friend istream& operator >> (istream& cin, CRatio& );
};
 

