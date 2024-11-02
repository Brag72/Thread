#pragma once
#include <string>
#include <vector>
#include "point.h"

class Shape
{
protected:
	std::vector<Point> _Points;

public:
	virtual ~Shape() = default;

	virtual double GetSqr() const = 0;
	virtual double GetVol() const = 0;


	virtual void Translate(double x, double y, double z, bool subtract = false) = 0;
	virtual void Scale(double x, double y, double z) = 0;
	virtual void UniformScale(double fac) { Scale(fac, fac, fac); }
	
};