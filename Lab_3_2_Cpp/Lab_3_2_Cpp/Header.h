#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Point {
private:
	int x;
	int y;
	int z;
public:
	Point();
	Point(int, int);
	int getX() { return x; }
	int getY() { return y; }
};
class Coordinates {
private:
	vector<Point>Vectors;
	double splash;
public:
	void FillDots();
	void CountSplash();
	double getSplash() { return splash; }
};