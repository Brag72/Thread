#include"sqr.h"
#include <stdexcept>

Sqr::Sqr(const std::vector<Point>& Points)
{
	if (Points.size() != 4)
	{
		throw std::invalid_argument("Прямоугольник должен иметь 4 точки.");
	}
	_Points = Points;
	S = new Sides(abs(_Points[0].GetX() - _Points[1].GetX()), abs(_Points[0].GetY() - _Points[1].GetY()), 0);

}

void Sqr::Translate(double x, double y, double z, bool subtract)
{
	for (auto& p : _Points)
	{
		p.Translate(x, y, z, subtract);
	}
}
void Sqr::Scale(double x, double y, double z)
{
	for (auto& p : _Points)
	{
		p.Scale(x, y, z);
	}
}
double Sqr::GetSqr() const
{
	//Предпологаем, что точки заданы в порядке обхода прямоугольника
	//_Points[0] - _Points[1] и _Points[1] - _Points[2] - смежные стороны

	double Side1 = Point::distance(_Points[0], _Points[1]);
	double Side2 = Point::distance(_Points[1], _Points[2]);
	return Side1 * Side2;
}