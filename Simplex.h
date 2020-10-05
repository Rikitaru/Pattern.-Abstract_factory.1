#pragma once
#include "Header.h"

class Simplex
{
private:
	//source - симплекс таблица без базисных переменных
	double ** table; //симплекс таблица
	int m, n;
	double * basis; //список базисных переменных
public:
	Simplex(double **source, int num_of_row, int num_of_col);
	
	//result - в этот массив будут записаны полученные значения X
	int Calculate(double *result);	

	bool IsItEnd();	
	int findMainCol();
	int findMainRow(int mainCol);
};

