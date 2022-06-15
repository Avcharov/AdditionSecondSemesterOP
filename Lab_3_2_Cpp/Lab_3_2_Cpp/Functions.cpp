#include "Functions.h"

vector<Coordinates> DotInput(int num, vector<Coordinates> Triangles) {
	for (int i = 0; i < num; i++)
	{
		Coordinates temp;
		temp.FillDots();
		Triangles.push_back(temp);
		Triangles[i].CountSplash();
	}
	return Triangles;
}

double Max(int num, vector<Coordinates> Triangles) {
	double max = 0;
	for (int i = 0; i < num; i++)
	{
		if (Triangles[i].getSplash() > max)
		{
			max = Triangles[i].getSplash();
		}
	}
	return max;
}

