#pragma once
#include "shape.h"

class vector;

class Line :public Shape
{
public:
	Line(const Point& Start, const Point& End);
	virtual void Translate(double x, double y, double z, bool subtract = false) override;
	virtual void Scale(double x, double y, double z) override;

	virtual double GetSqr() const override { return 0; }
	virtual double GetVol() const override { return 0; }
};