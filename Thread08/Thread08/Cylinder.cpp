#include"Cylinder.h"
#include <stdexcept>

Cylinder::Cylinder(const Point& Center, double Rad, double Height):_Center(Center),_Radius(Rad),_Height(Height)
{
	if(Height <= 0)
	{ 
		throw std::invalid_argument("Цилиндер должен иметь высоту!");
	}
}

void Cylinder::Translate(double x, double y, double z, bool subtract)
{
	_Center.Translate(x, y, z, subtract);
}
void Cylinder::Scale(double x, double y, double z)
{
	if (x == y && y == z)
	{
		_Height = _Radius *= std::max({ x,y,z });
	}
	else
	{
		_Radius *= x + y;
		_Height *= z;
	}
}