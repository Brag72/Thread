#include "point.h"
#include "cmath"

void Point::Translate(double x, double y, double z, bool subtract)
{
	if (subtract)
	{
		_X -= x;
		_Y -= y;
		_Z -= z;
	}
	else
	{
		_X += x;
		_Y += y;
		_Z += z;
	}
}
void Point::Scale(double x, double y, double z)
{
	_X *= x;
	_Y *= y;
	_Z *= z;
}
double Point::distance(const Point& P1, const Point& P2)
{
	double DX = P2._X - P1._X;
	double DY = P2._Y - P1._Y;
	double DZ = P2._Z - P1._Z;
	return std::sqrt(DX * DX + DY * DY + DZ * DZ);
}