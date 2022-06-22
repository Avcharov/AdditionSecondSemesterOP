#pragma once
#include "TSystemLinearEquation.h"
#include <string>
#include "GauseMethod.h"
#include "header.h"
#include "get_vars.h"


class SystemLinearEquationWith2 : public TSystemLinearEquation {
protected:
	double x, y;
public:
	SystemLinearEquationWith2(vector <Equation> equations) :
		TSystemLinearEquation(equations) {};

	void find_solution() override
	{
		int size = getRank();
		double** matr_a = new double* [size];

		for (size_t i = 0; i < size; i++)
		{
			matr_a[i] = new double[size];
		}

		for (size_t i = 0; i < size; i++)
		{
			for (size_t j = 0; j < size; j++)
			{
				matr_a[i][j] = getEquation(i).getKoef(j);
			}
		}

		double* matr_b = new double[size];
		for (size_t i = 0; i < size; i++)
		{
			matr_b[i] = getEquation(i).getSolution();
		}

		double* roots = new double[size];
		for (size_t i = 0; i < size; i++)
		{
			roots[i] = NULL;
		}

		solve_with_gause(size, matr_a, matr_b, roots);

		x = ceil(roots[0] * 100.0) / 100.0;
		y = ceil(roots[1] * 100.0) / 100.0;

		if (isinf(x) || isinf(y))
		{
			cout << "There is no pair of roots." << endl;
		}
		else
		{
			cout << "x: " << x << " y: " << y << endl;
		}
	}

	bool is_roots(string to_check) override
	{
		vector<double> vars;
		vars = get_vars(to_check, ' ');

		bool is_roots = false;

		if (vars.size() == getRank())
		{
			double x_toCheck = vars[0];
			double y_toCheck = vars[1];

			if (x_toCheck == this->x and y_toCheck == this->y)
			{
				is_roots = true;
			}
		}
		return is_roots;
	}
};