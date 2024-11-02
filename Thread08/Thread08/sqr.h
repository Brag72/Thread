#pragma once
#include "shape.h"
#include "SidesStruct.h"

class vector;

class Sqr :public Shape
{
	Sides* S;

public:
	Sqr(const std::vector<Point>& Points);
	virtual void Translate(double x, double y, double z, bool subtract = false) override;
	virtual void Scale(double x, double y, double z) override;

	virtual double GetSqr() const override;
	virtual double GetVol() const override { return 0; }
};