#pragma once
#include <vector>
#include <iostream>

using namespace std;


class Equation {
private:
	vector <int> koefs;
	int solution;
public:
	Equation() {};

	Equation(vector <int> _koefs)
	{
		for (size_t i = 0; i < _koefs.size(); i++)
		{
			if (i != _koefs.size() - 1) {
				this->koefs.push_back(_koefs[i]);
			}
			else {
				this->solution = _koefs[i];
			}
		}
	}

	void display_eq() {
		for (size_t i = 0; i < koefs.size(); i++)
		{
			if (i == 0) {
				cout << koefs[i] << char(120 + i) << " ";
			}
			else if (i == koefs.size() - 1) {
				cout << "= " << solution << endl;
			}
			else {
				cout << "+ " << koefs[i] << char(120 + i);
			}
		}
	}

	double getKoef(int index)
	{
		return this->koefs[index];
	}

	double getSolution() {
		return this->solution;
	}
};