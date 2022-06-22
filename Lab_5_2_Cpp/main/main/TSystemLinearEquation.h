#pragma once
#include "Equation.h"


class TSystemLinearEquation {
protected:
	vector <Equation> equations;
	int rank;
public:
	virtual void find_solution() = 0;
	virtual bool is_roots(string) = 0;

	TSystemLinearEquation(vector <Equation> equations) {
		this->rank = equations.size();

		for (size_t i = 0; i < equations.size(); i++)
		{
			this->equations.push_back(equations[i]);
		}
	}

	void display_system()
	{
		for (size_t i = 0; i < rank; i++)
		{
			this->equations[i].display_eq();
		}
	}

	int getRank()
	{
		return this->rank;
	}

	Equation getEquation(int index)
	{
		return this->equations[index];
	}
};