#include "Functions.h"
#include "Header.h"
using namespace std;


int main()
{
	vector<Coordinates> Triangles;
	int num;
	cout << "Input the num of triangles - ";
	cin >> num;
	cout << "Input the coordinates of the dots - ";
	Triangles = DotInput(num,Triangles);
	double max = Max(num, Triangles);
	
	cout << "The max splash is - " << max << endl;
	
	
}

