#pragma once
#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
using namespace std;
# define M_PI           3.14159265358979323846

class Vector {
private:
	double length;
	double angle;
public:
	Vector();
	Vector(double, double);
	Vector(Vector& obj);
	void Rotate(double);
	void print();
	double getAngle() { return angle; }
	double getLength() { return length; }
	Vector operator+(Vector obj);
	Vector operator/(int a);


};