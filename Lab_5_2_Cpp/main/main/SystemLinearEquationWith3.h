#pragma once
#include "Equation.h"
#include "SystemLinearEquationWith2.h"
#include "get_vars.h"

class SystemLinearEquationWith3 : public SystemLinearEquationWith2 {
protected:
	double z;
public:
	SystemLinearEquationWith3(vector <Equation> equations) :
		SystemLinearEquationWith2(equations) {};

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
		z = ceil(roots[2] * 100.0) / 100.0;

		if (isinf(x) || isinf(y) || isinf(z))
		{
			cout << "There is no pair of roots." << endl;
		}
		else
		{
			cout << "x: " << x << " y: " << y << " z: " << z << endl;
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
			double z_toCheck = vars[2];

			if (x_toCheck == this->x && y_toCheck == this->y && z_toCheck == this->z)
			{
				is_roots = true;
			}
		}
		return is_roots;
	}
};