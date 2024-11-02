#pragma once
#include "shape.h"
#define _USE_MATH_DEFINES
#include <math.h>

class vector;

class Cylinder :public Shape
{
	Point _Center;
	double _Radius;
	double _Height;	

public:
	Cylinder(const Point& Center, double Rad, double Height);
	virtual void Translate(double x, double y, double z, bool subtract = false) override;
	virtual void Scale(double x, double y, double z) override;

	virtual double GetSqr() const override { return 2 * M_PI * _Radius * _Radius + 2 * M_PI * _Radius * _Height; }
	virtual double GetVol() const override { return M_PI * _Radius * _Radius * _Height; }
};