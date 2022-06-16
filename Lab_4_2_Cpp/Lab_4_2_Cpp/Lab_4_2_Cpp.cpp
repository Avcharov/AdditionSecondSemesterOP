#include "Header.h"
using namespace std;
# define M_PI 3.14159265358979323846
int main()
{
	Vector B3(4, 45);
	cout << "B3 Start value - ";
	B3.print();
	Vector B2(B3);
	cout << "B2 Start value - ";
	B2.print();
	B3.Rotate(45);
	B2 = B2 / 2;
	Vector B1;
	B1 = B2 + B3;
	cout <<" End values : "<<endl;
	B1.print();
	B2.print();
	B3.print();

}

