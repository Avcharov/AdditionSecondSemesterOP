#pragma once
#include <cmath>


void solve_with_gause(int size, double** matr_a, double* matr_b, double* roots) {
	double v;
	int i, j, k, im;

	for (int k = 0; k < size - 1; k++)
	{
		im = k;
		for (i = k + 1; i < size; i++)
		{
			if (fabs(matr_a[im][k]) < fabs(matr_a[i][k]))
			{
				im = i;
			}
		}
		if (im != k)
		{
			for (j = 0; j < size; j++)
			{
				v = matr_a[im][j];
				matr_a[im][j] = matr_a[k][j];
				matr_a[k][j] = v;
			}
			v = matr_b[im];
			matr_b[im] = matr_b[k];
			matr_b[k] = v;
		}
		for (i = k + 1; i < size; i++)
		{
			v = 1.0 * matr_a[i][k] / matr_a[k][k];
			matr_a[i][k] = 0;
			matr_b[i] = matr_b[i] - v * matr_b[k];
			if (v != 0)
			{
				for (j = k + 1; j < size; j++)
				{
					matr_a[i][j] = matr_a[i][j] - v * matr_a[k][j];
				}
			}
		}
	}

	double s = 0;
	roots[size - 1] = 1.0 * matr_b[size - 1] / matr_a[size - 1][size - 1];
	for (int i = size - 2, j; 0 <= i; i--)
	{
		s = 0;
		for (j = i + 1; j < size; j++)
		{
			s = s + matr_a[i][j] * roots[j];
		}
		roots[i] = 1.0 * (matr_b[i] - s) / matr_a[i][i];
	}
}