#pragma once
#include <random>
#include "Equation.h"
#include "SystemLinearEquationWith2.h"
#include "SystemLinearEquationWith3.h"


vector <Equation> generate_equations(int mode) {
	vector <Equation> equations;
	for (size_t j = 0; j < mode; j++)
	{
		vector <int> koefs = {};
		for (size_t k = 0; k < mode + 2; k++)
		{
			int koef;
			koef = rand() % (5 + 5 - 1) - 5; // [-5; 5]

			koefs.push_back(koef);
		}

		Equation temp_eq = Equation(koefs);
		equations.push_back(temp_eq);
	}
	return equations;
}

void fill_systems(vector <TSystemLinearEquation*>& all_systems, int amount_of_two, int amount_of_three) {
	int mode;

	for (size_t i = 0; i < amount_of_two + amount_of_three; i++)
	{
		vector <Equation> temp_eq;
		if (i < amount_of_two) {
			mode = 2;

			temp_eq = generate_equations(mode);
			all_systems.push_back(new SystemLinearEquationWith2(temp_eq));
		}
		else {
			mode = 3;

			temp_eq = generate_equations(mode);
			all_systems.push_back(new SystemLinearEquationWith3(temp_eq));
		}
	}
}