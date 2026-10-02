#include<iostream>
using namespace std;

class Cpoint
{
private:
	int m_x;
	int m_y;
public:
	Cpoint();
	Cpoint(int, int);
	~Cpoint();
    Cpoint operator+=(const Cpoint&);
    Cpoint operator+(const Cpoint&);
    Cpoint operator-=(const Cpoint&);
    Cpoint operator-(const Cpoint&);
    Cpoint operator*=(const Cpoint&);
    Cpoint operator*(const Cpoint&);
	void affiche();
	void translate(int dx, int dy);
	Cpoint (int x);
	bool Coincide(Cpoint);
};

