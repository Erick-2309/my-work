#include<iostream>
using namespace std;


class Cvect
{
   private:
       int m_N;
       double* m_ptab;
   public:
    Cvect(int=0);
    ~Cvect();
    Cvect(int, double*);
    Cvect(const Cvect&);
    friend ostream& operator<<(ostream&, const Cvect&);
    friend istream& operator>>(istream&, Cvect&);
    void Random();
    Cvect operator+(const Cvect&);
    Cvect operator+=(const Cvect&);
    Cvect operator*(const Cvect&);
    void Permute (int i, int j);
    void TriSelection();
    int min();
    void TriBulles(bool);
    void TriInsertion();
};






















/* Cvect(int);
 Cvect(int, double*);
 Cvect(const Cvect&);
 ~Cvect();
 double Prod_Scal(const Cvect &);
 Cvect Prod_Simpl(int); //Prod_Simpl(produit simple )
 Cvect operator+=(const Cvect&);
 Cvect operator+(const Cvect&);
 friend ostream &operator<<(ostream &, const Cvect &);
 friend istream &operator>>(istream &, Cvect &);*/
