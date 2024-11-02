#pragma once
#include"shape.h"

class transform
{
public:
	static void Translate(Shape& shape, double x, double y, double z, bool subtract = false)
	{
		shape.Translate(x, y, z, subtract);
	}
	static void Scale(Shape& shape, double x, double y, double z)
	{
		shape.Scale(x, y, z);
	}
};
