#include "Simplex.h"

Simplex::Simplex(double ** source, int num_of_row, int num_of_col)
{
	m = num_of_row;
	n = num_of_col;
	table = new double*[m];
	for (int i = 0; i < m; i++)
	{
		table[i] = new double[n + m - 1];
	}

	basis = new double[m - 1];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < (n + m - 1); j++)
		{
			if (j < n)
				table[i][j] = source[i][j];
			else
				table[i][j] = 0;
		}
		//выставляем коэффициент 1 перед базисной переменной в строке
		if ((n + i) < (n + m - 1))
		{
			table[i][n + i] = 1; //создаём единичную матрицу
			basis[i] = n + i;
		}
	}
	n = n + m - 1;
}

int Simplex::Calculate(double * result)
{
	int mainCol, mainRow; //ведущие столбец и строка

	while (!IsItEnd())
	{
		mainCol = findMainCol();
		mainRow = findMainRow(mainCol);
		basis[mainRow] = mainCol;

		double ** new_table = new double*[m];//, n];
		for (int i = 0; i < m; i++) { new_table[i] = new double[n]; }

		for (int j = 0; j < n; j++)
			new_table[mainRow][j] = table[mainRow][j] / table[mainRow][mainCol];

		for (int i = 0; i < m; i++)
		{
			if (i == mainRow)
				continue;

			for (int j = 0; j < n; j++)
				new_table[i][j] = table[i][j] - table[i][mainCol] * new_table[mainRow][j];
		}
		table = new_table;
	}

	//заносим в result найденные значения X
	for (int i = 0; i < _msize(result) / sizeof(*result); i++)
	{
		bool flag = true;
		int k;

		for (int j = 0; j < _msize(basis) / sizeof(*basis); j++) { if (basis[j] == i + 1) { k = j; flag = false; break; } }
		if (flag) { k = -1; }

		if (k != -1)
			result[i] = table[k][0];
		else
			result[i] = 0;
	}
	//проверочка
	for (int i = 0; i < _msize(result) / sizeof(*result); i++)
	{
		cout << "result[" << i << "] = " << result[i];
	}
	return table[m - 1][0];
}

bool Simplex::IsItEnd()
{
	bool flag = true;

	for (int j = 1; j < n; j++)
	{
		if (table[m - 1][j] < 0)
		{
			flag = false;
			break;
		}
	}
	return flag;
}

int Simplex::findMainCol()
{
	int mainCol = 1;

	for (int j = 2; j < n; j++)
		if (table[m - 1][j] < table[m - 1][mainCol])
			mainCol = j;

	return mainCol;
}

int Simplex::findMainRow(int mainCol)
{
	int mainRow = 0;

	for (int i = 0; i < m - 1; i++)
		if (table[i][mainCol] > 0)
		{
			mainRow = i;
			break;
		}

	for (int i = mainRow + 1; i < m - 1; i++)
		if ((table[i, mainCol] > 0) && ((table[i][0] / table[i][mainCol]) < (table[mainRow][0] / table[mainRow][mainCol])))
			mainRow = i;

	return mainRow;
}
