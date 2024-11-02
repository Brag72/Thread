#pragma once
#include "shape.h"
#define _USE_MATH_DEFINES
#include <math.h>

class vector;

class Circle :public Shape
{
	Point _Center;
	double _Radius;

public:
	Circle(const Point& Center, double Rad);
	virtual void Translate(double x, double y, double z, bool subtract = false) override;
	virtual void Scale(double x, double y, double z) override;

	virtual double GetSqr() const override { return M_PI * _Radius * _Radius; }
	virtual double GetVol() const override { return 0; }
};