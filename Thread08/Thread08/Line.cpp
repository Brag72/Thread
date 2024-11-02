#include"Line.h"
#include <stdexcept>

Line::Line(const Point& Start, const Point& End)
{
	_Points.push_back(Start);
	_Points.push_back(End);
}

void Line::Translate(double x, double y, double z, bool subtract)
{
	for (auto& p : _Points)
	{
		p.Translate(x, y, z, subtract);
	}
}
void Line::Scale(double x, double y, double z)
{
	for (auto& p : _Points)
	{
		p.Scale(x, y, z);
	}
}