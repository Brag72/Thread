#include<iostream>
#include"transform.h"
#include <windows.h>
#include "point.h"
#include "Circle.h"
#include "Line.h"
#include "Cube.h"
#include "Cylinder.h"
#include "Sqr.h"
#include <vector>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale(LC_ALL, "Russian");

	Cube cube({Point(-5,-5,-5), Point(-5,5,-5), Point(5,5,-5), Point(5,-5,-5), Point(-5,-5,5), Point(-5,5,5), Point(5,5,5), Point(5,-5,5)});
	Sqr sqr({ Point(-5,-5,-5), Point(5,-5,-5), Point(-5,-5,0), Point(5,-5,0) });
	Line line(Point(11, 15, 12), Point(12, 15, 11));
	Circle circle(Point(0, 0, 0),10.0);
	Cylinder cylinder(Point(0, 0, 0), 10.0,20.0);

	cout << "Площадь куба: " << cube.GetSqr() << " | " << "Объём куба: " << cube.GetVol() << endl;
	cout << "Площадь прямоугольника: " << sqr.GetSqr() << " | " << "Объём прямоугольника: " << sqr.GetVol() << endl;
	cout << "Площадь линии: " << line.GetSqr() << " | " << "Объём линии: " << line.GetVol() << endl;
	cout << "Площадь круга: " << circle.GetSqr() << " | " << "Объём круга: " << circle.GetVol() << endl;
	cout << "Площадь цилиндра: " << cylinder.GetSqr() << " | " << "Объём цилиндра: " << cylinder.GetVol() << endl;

	transform::Scale(cube, 5, 5, 5);

	cout << "Площадь куба после scale: " << cube.GetSqr() << " | " << "Объём куба после scale: " << cube.GetVol() << endl;
}