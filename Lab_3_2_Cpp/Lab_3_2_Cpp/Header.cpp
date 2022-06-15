#include "Header.h"
using namespace std;
Point::Point(int x1, int y1) {
	x = x1;
	y = y1;
}
void Coordinates::CountSplash() {
	int value = 4;
	double** matrix = new double* [value];
	for (int i = 0; i < value; i++) {
		matrix[i] = new double[value];
	}
	for (int i = 0; i < value; i++) {
		for (int j = 0; j < value; j++) {
			matrix[i][j] = 0;
		}
	}
	matrix[0][0] = Vectors[0].getX() - Vectors[2].getX();
	matrix[0][1] = Vectors[0].getY() - Vectors[2].getY();
	matrix[1][0] = Vectors[1].getX() - Vectors[2].getX();
	matrix[1][1] = Vectors[1].getY() - Vectors[2].getY();
	double determinant = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
	splash = 0.5 * abs(determinant);
}
void Coordinates::FillDots() {
	int x, y;
	for (int i = 0; i < 3; i++) {
		cout << "Enter x" << i << ": ";
		cin >> x;
		cout << "Enter y" << i << ": ";
		cin >> y;
		Point dot(x, y);
		Vectors.push_back(dot);
	}
}
