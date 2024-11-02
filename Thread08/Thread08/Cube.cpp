#include"Cube.h"
#include <stdexcept>

Cube::Cube(const std::vector<Point>& Points)
{
	if (Points.size() != 8)
	{
		throw std::invalid_argument(" уб должен иметь 8 точек.");
	}
	_Points = Points;

	S = new Sides(abs(_Points[0].GetX() - _Points[3].GetX()),
		abs(_Points[0].GetY() - _Points[1].GetY()),
		abs(_Points[0].GetZ() - _Points[4].GetZ()));
}

void Cube::Translate(double x, double y, double z, bool subtract)
{
	for (auto& p : _Points)
	{
		p.Translate(x, y, z, subtract);
	}
}
void Cube::Scale(double x, double y, double z)
{
	for (auto& p : _Points)
	{
		p.Scale(x, y, z);
	}
}

double Cube::GetSqr() const 
{ 
	//ѕредполагаем, что точки заданы в следующем пор€дке:
	//_Points[0 - 3] - нижн€€ грань(по часовой)
	//_Points[4 - 7] - верхн€€ грань(по часовой)

	double Length = Point::distance(_Points[0], _Points[1]);
	double Width = Point::distance(_Points[1], _Points[2]);
	double Heigth = Point::distance(_Points[0], _Points[4]);

	return 2 * (Length * Width + Width * Heigth + Length * Heigth);
}

double Cube::GetVol() const
{ 
	double Length = Point::distance(_Points[0], _Points[1]);
	double Width = Point::distance(_Points[1], _Points[2]);
	double Heigth = Point::distance(_Points[0], _Points[4]);

	return Length * Heigth * Width;
}