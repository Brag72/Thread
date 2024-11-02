#include"Circle.h"
#include <stdexcept>

Circle::Circle(const Point& Center, double Rad) :_Center(Center), _Radius(Rad)
{
	if (Rad <= 0)
	{
		throw std::invalid_argument("Радиус круга должен быть положительным!");
	}
}

void Circle::Translate(double x, double y, double z, bool subtract)
{
	_Center.Translate(x, y, z, subtract);
}
void Circle::Scale(double x, double y, double z)
{
	if (x == y && y == z)
	{
		_Radius *= std::max({ x,y,z });
	}
	else
	{
		_Radius *= x + y;
	}
}