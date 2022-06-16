#include "Header.h"
using namespace std;
Vector::Vector() {
	length = 0;
	angle = 0;
}
Vector::Vector(double _length, double _angle) {
	length = _length;
	angle = _angle;
}
Vector::Vector(Vector& obj) {
	length = obj.length; angle = obj.angle;
}

void Vector::Rotate(double rotateAngle) {
	this->angle += rotateAngle;
}
void Vector::print() {
	cout << " Length : " << length << " Angle : " << angle << endl;
}

Vector Vector::operator+(Vector obj) {

	double a = sqrt(pow(length, 2) + pow(obj.length, 2) - 2 * length * obj.getLength() *
		cos(angle - obj.getAngle() + M_PI));
	double  b = asin(sin(angle - obj.getAngle() + M_PI) * obj.getLength() / a) - angle;
	Vector tmp(a, b);
	return tmp;
}
Vector Vector::operator/(int a) {
	double k = length / a;
	double b = angle;
	Vector tmp(k, b);
	return tmp;
}
