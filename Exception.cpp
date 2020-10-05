#include "Exception.h"

bool Exception::is_digit(int & digit, string text)
{
	char _digit[10];
	try
	{
		printf("%s", text.c_str());
		cin >> _digit;
		for (int i = 0; i < strlen(_digit); i++)
			if (!isdigit(_digit[i]))
				throw 7641;
		digit = atoi(_digit);
		return false;
	}
	catch (const int &ex)
	{
		SetColor(12, 1);
		cout << "Ошибка при вводе данных!" << endl << "Код ошибки: #" << ex << endl << "Введите данные ещё раз:\t" << endl;
		SetColor(14, 1);
		return true;
	}
}