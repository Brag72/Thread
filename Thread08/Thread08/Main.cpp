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

	cout << "������� ����: " << cube.GetSqr() << " | " << "����� ����: " << cube.GetVol() << endl;
	cout << "������� ��������������: " << sqr.GetSqr() << " | " << "����� ��������������: " << sqr.GetVol() << endl;
	cout << "������� �����: " << line.GetSqr() << " | " << "����� �����: " << line.GetVol() << endl;
	cout << "������� �����: " << circle.GetSqr() << " | " << "����� �����: " << circle.GetVol() << endl;
	cout << "������� ��������: " << cylinder.GetSqr() << " | " << "����� ��������: " << cylinder.GetVol() << endl;

	transform::Scale(cube, 5, 5, 5);

	cout << "������� ���� ����� scale: " << cube.GetSqr() << " | " << "����� ���� ����� scale: " << cube.GetVol() << endl;
}