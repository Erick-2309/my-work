#pragma once
#include "CVec2.h"
class CVec3 : public CVec2
{
private:
	double m_x3;
public:
	CVec3(double =0.0, double=0.0, double = 0.0);
	~CVec3();
	virtual void aff();
};

