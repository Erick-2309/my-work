#include "Cpoint.h"

Cpoint::Cpoint()
{
	//cout << "passage dans le  contructeur sans paramatres" << endl;
	m_x=0;
	m_y=0;
}
Cpoint::Cpoint(int x, int y)
{
	//cout << "passage dans le contructeur avec paramatres" << endl;
	m_x =x;
	m_y =y;
}
Cpoint::~Cpoint()
{
	cout << "passage dans le destructeur" << endl;
}

Cpoint Cpoint:: operator+=(const Cpoint& p)
{
    m_x += p.m_x;
    m_y += p.m_y;
    return *this;
}

Cpoint Cpoint:: operator+(const Cpoint& p)
{
    Cpoint resulte ;
    resulte= *this+=p;
    return resulte;
}

Cpoint Cpoint:: operator-=(const Cpoint& p)
{
    m_x -= p.m_x;
    m_y -= p.m_y;
    return *this;
}

Cpoint Cpoint:: operator-(const Cpoint& p)
{
    Cpoint resulte ;
    resulte= *this-=p;
    return resulte;
}



void Cpoint::affiche()
{
	cout << "le point vaut:(" << m_x << "," << m_y << ")"<<endl;

}

 
void Cpoint::translate(int dx, int dy)
{
	m_x +=dx;
	m_y =m_y + dy;
}
Cpoint::Cpoint(int x)
{
	cout << "passage dans le  contructeur avec paramatres" << endl;
    m_x = x ;
    m_y = x ;
}

bool Cpoint::Coincide(Cpoint C)
{
   // m_x = C.m_x ;
    //m_y = C.m_y;
	if((m_x ==C.m_x ) && (m_y==C.m_y))
	{
        //cout<< true<<endl;
        return true;
	}
	else
	{
        //cout<< false<<endl;
        return false;
	}
    
}


