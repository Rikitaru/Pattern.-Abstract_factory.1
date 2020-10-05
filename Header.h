#pragma once

#include <iostream>
#include <malloc.h>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#pragma warning (disable : 4996)

#define N 1000

using namespace std;
const int NotUsed = system("color 1E");

inline void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}