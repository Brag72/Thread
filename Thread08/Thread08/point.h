#pragma once

class Point
{
	double _X, _Y, _Z;

public:
	Point(double X, double Y, double Z) : _X(X), _Y(Y), _Z(Z) {};
	void Translate(double x, double y, double z,bool subtract = false);
	void Scale(double x, double y, double z);

	static double distance(const Point& P1, const Point& P2);
	

	double GetX() const { return _X; }
	double GetY() const { return _Y; }
	double GetZ() const { return _Z; }
};
