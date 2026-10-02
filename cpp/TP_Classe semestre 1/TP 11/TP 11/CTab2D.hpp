#include<iostream>
using namespace std;


class CTab2D
{
private:
    int m_nL;
    int m_nC;
    double **m_pTab;
public:
    void Alloc(int, int);  //pour allouer le pointeur m_pTab
    void Free();           // pour libérer le pointeur m_pTab
    void Init(int l=1, int c=1, double val=0.0);//pour initialiser m_nL, m_nC et le tableau m_pTab à l’aide de val.
    CTab2D (int l=1, int c=1, double val=0.0);
    ~CTab2D();
    CTab2D (const CTab2D&);
    CTab2D FillRand();
    friend ostream& operator<<(ostream&, const CTab2D&);
    friend istream& operator>>(istream&,CTab2D&);
    CTab2D operator=(double**);
    CTab2D operator=(const CTab2D&);
    double cellule(int i=1, int j=1);
    void set (int i=0, int j=0, double v=0);
    CTab2D operator()(int,int);
    CTab2D operator+(const CTab2D&);
    CTab2D operator+=(const CTab2D&);
    CTab2D operator+=(double val);
    CTab2D operator*(double val);
    friend CTab2D operator*(double val, const CTab2D &);
    CTab2D operator*(const CTab2D&);
    CTab2D Diagonale();
    CTab2D T_sup();
    CTab2D T_inf();
};
