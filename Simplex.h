#pragma once
#include "Header.h"

class Simplex
{
private:
	//source - �������� ������� ��� �������� ����������
	double ** table; //�������� �������
	int m, n;
	double * basis; //������ �������� ����������
public:
	Simplex(double **source, int num_of_row, int num_of_col);
	
	//result - � ���� ������ ����� �������� ���������� �������� X
	int Calculate(double *result);	

	bool IsItEnd();	
	int findMainCol();
	int findMainRow(int mainCol);
};

