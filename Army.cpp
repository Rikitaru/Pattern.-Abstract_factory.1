#include "Army.h"

Army::Army()
{
	TA = nullptr;
	AC = nullptr;
	MR = nullptr;
	AR = nullptr;
	FP = nullptr;

	TA_size = NULL;
	AC_size = NULL;
	MR_size = NULL;
	AR_size = NULL;
	FP_size = NULL;

	country_budget = NULL;
	storage_budget = NULL;
	military_base_territory = NULL;
	requirement_power = NULL;

	TA = new Tank*[N];
	AC = new Armored_carrier*[N];
	MR = new Military_robot*[N];
	AR = new Artillery*[N];
	FP = new Fighter_plane*[N];
}

int Army::get_requirement_power()
{
	return requirement_power;
}

void Army::initialization()
{
	Exception ex;
	string text = "Введите бюджет, на создание военной базы >> ";
	while (ex.is_digit(country_budget, text)); // исключение
	text = "Введите бюджет, для хранения техники >> ";
	while (ex.is_digit(storage_budget, text));
	text = "Введите территорию военной базы >> ";
	while (ex.is_digit(military_base_territory, text));
	cout << endl;
	text = "Введите контингент танков на военной базе >> ";
	while (ex.is_digit(TA_size, text));
	text = "Введите контингент бронетранспортёров на военной базе >> ";
	while (ex.is_digit(AC_size, text));
	text = "Введите контингент военных роботов на военной базе >> ";
	while (ex.is_digit(MR_size, text));
	text = "Введите контингент артиллерии на военной базе >> ";
	while (ex.is_digit(AR_size, text));
	text = "Введите контингент самолётов на военной базе >> ";
	while (ex.is_digit(FP_size, text));
}

void Army::set()
{
	for (int i = 0; i < TA_size; ++i)  TA[i]->set();
	for (int i = 0; i < AC_size; ++i)  AC[i]->set();
	for (int i = 0; i < MR_size; ++i)  MR[i]->set();
	for (int i = 0; i < AR_size; ++i)  AR[i]->set();
	for (int i = 0; i < FP_size; ++i)  FP[i]->set();
}

void Army::info()
{
	cout << endl << "Бюджет военной базы = " << country_budget << endl;
	cout << "Бюджет для хранения техники = " << storage_budget << endl;
	cout << "Территоря военной базы = " << military_base_territory << endl;
	cout << "Огневая мощь контингента на военной базе = " << requirement_power << endl;
	for (int i = 0; i < TA_size; ++i)  TA[i]->info();
	for (int i = 0; i < AC_size; ++i)  AC[i]->info();
	for (int i = 0; i < MR_size; ++i)  MR[i]->info();
	for (int i = 0; i < AR_size; ++i)  AR[i]->info();
	for (int i = 0; i < FP_size; ++i)  FP[i]->info();
}

void Army::save_to_file(const char * filename)
{
	ofstream f;
	char buffer_char[20];
	int buffer_int;
	try
	{
		f.open(filename, ios::binary | ios::out);
		if (!f.is_open()) {
			throw 505;
		}

		f.write(reinterpret_cast<char*>(&country_budget), sizeof(int));
		f.write(reinterpret_cast<char*>(&storage_budget), sizeof(int));
		f.write(reinterpret_cast<char*>(&military_base_territory), sizeof(int));
		f.write(reinterpret_cast<char*>(&requirement_power), sizeof(int));

		f.write(reinterpret_cast<char*>(&TA_size), sizeof(int));
		f.write(reinterpret_cast<char*>(&AC_size), sizeof(int));
		f.write(reinterpret_cast<char*>(&MR_size), sizeof(int));
		f.write(reinterpret_cast<char*>(&AR_size), sizeof(int));
		f.write(reinterpret_cast<char*>(&FP_size), sizeof(int));

		for (int i = 0; i < TA_size; i++) {
			strcpy(buffer_char, TA[i]->get_name());				f.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			buffer_int = TA[i]->get_cost();						f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TA[i]->get_storage_cost();				f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TA[i]->get_occupied_space();			f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TA[i]->get_firepower();				f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = TA[i]->get_number_in_the_army();		f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
		}
		for (int i = 0; i < AC_size; i++) {
			strcpy(buffer_char, AC[i]->get_name());				f.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			buffer_int = AC[i]->get_cost();						f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = AC[i]->get_storage_cost();				f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = AC[i]->get_occupied_space();			f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = AC[i]->get_firepower();				f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = AC[i]->get_number_in_the_army();		f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
		}
		for (int i = 0; i < MR_size; i++) {
			strcpy(buffer_char, MR[i]->get_name());				f.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			buffer_int = MR[i]->get_cost();						f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = MR[i]->get_storage_cost();				f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = MR[i]->get_occupied_space();			f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = MR[i]->get_firepower();				f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = MR[i]->get_number_in_the_army();		f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
		}
		for (int i = 0; i < AR_size; i++) {
			strcpy(buffer_char, AR[i]->get_name());				f.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			buffer_int = AR[i]->get_cost();						f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = AR[i]->get_storage_cost();				f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = AR[i]->get_occupied_space();			f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = AR[i]->get_firepower();				f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = AR[i]->get_number_in_the_army();		f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
		}
		for (int i = 0; i < FP_size; i++) {
			strcpy(buffer_char, FP[i]->get_name());				f.write(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));
			buffer_int = FP[i]->get_cost();						f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = FP[i]->get_storage_cost();				f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = FP[i]->get_occupied_space();			f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = FP[i]->get_firepower();				f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
			buffer_int = FP[i]->get_number_in_the_army();		f.write(reinterpret_cast<char*>(&buffer_int), sizeof(int));
		}

		f.close();
	}
	catch (const int ex)
	{
		SetColor(12, 1);
		cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
		SetColor(14, 1);
	}
}

void Army::read_from_file(const char * filename, ArmyFactory & factory)
{
	char buffer_char[20];
	int buffer_int;
	ifstream in;
	try
	{
		in.open(filename, ios::binary | ios::in);
		if (!in.is_open()) {
			throw 505;
		}

		in.read(reinterpret_cast<char*>(&country_budget), sizeof(int));
		in.read(reinterpret_cast<char*>(&storage_budget), sizeof(int));
		in.read(reinterpret_cast<char*>(&military_base_territory), sizeof(int));
		in.read(reinterpret_cast<char*>(&requirement_power), sizeof(int));

		in.read(reinterpret_cast<char*>(&TA_size), sizeof(int));
		in.read(reinterpret_cast<char*>(&AC_size), sizeof(int));
		in.read(reinterpret_cast<char*>(&MR_size), sizeof(int));
		in.read(reinterpret_cast<char*>(&AR_size), sizeof(int));
		in.read(reinterpret_cast<char*>(&FP_size), sizeof(int));


		for (int i = 0; i < TA_size; ++i)  TA[i] = factory.create_Tank();
		for (int i = 0; i < AC_size; ++i)  AC[i] = factory.create_Armored_carrier();
		for (int i = 0; i < MR_size; ++i)  MR[i] = factory.create_Military_robot();
		for (int i = 0; i < AR_size; ++i)  AR[i] = factory.create_Artillery();
		for (int i = 0; i < FP_size; ++i)  FP[i] = factory.create_Fighter_plane();

		for (int i = 0; i < TA_size; i++) {
			in.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	TA[i]->set_name(buffer_char);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TA[i]->set_cost(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TA[i]->set_storage_cost(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TA[i]->set_occupied_space(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TA[i]->set_firepower(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				TA[i]->set_number_in_the_army(buffer_int);
		}
		for (int i = 0; i < AC_size; i++) {
			in.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	AC[i]->set_name(buffer_char);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				AC[i]->set_cost(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				AC[i]->set_storage_cost(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				AC[i]->set_occupied_space(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				AC[i]->set_firepower(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				AC[i]->set_number_in_the_army(buffer_int);
		}
		for (int i = 0; i < MR_size; i++) {
			in.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	MR[i]->set_name(buffer_char);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				MR[i]->set_cost(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				MR[i]->set_storage_cost(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				MR[i]->set_occupied_space(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				MR[i]->set_firepower(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				MR[i]->set_number_in_the_army(buffer_int);
		}
		for (int i = 0; i < AR_size; i++) {
			in.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	AR[i]->set_name(buffer_char);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				AR[i]->set_cost(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				AR[i]->set_storage_cost(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				AR[i]->set_occupied_space(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				AR[i]->set_firepower(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				AR[i]->set_number_in_the_army(buffer_int);
		}
		for (int i = 0; i < FP_size; i++) {
			in.read(reinterpret_cast<char*>(&buffer_char), sizeof(buffer_char));	FP[i]->set_name(buffer_char);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				FP[i]->set_cost(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				FP[i]->set_storage_cost(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				FP[i]->set_occupied_space(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				FP[i]->set_firepower(buffer_int);
			in.read(reinterpret_cast<char*>(&buffer_int), sizeof(int));				FP[i]->set_number_in_the_army(buffer_int);
		}

		info();
		in.close();
	}
	catch (const int &ex)
	{
		SetColor(12, 1);
		cout << "Ошибка открытия файла!" << endl << "Код ошибки: #" << ex << endl;
		SetColor(14, 1);
	}
}

void Army::Who_is_more_powerful(void)
{
	int NUM = 4;		//количество уравнений + целевая функция
	int tmp = NULL;

	//Этап 1. построение и заполнение симплексной таблицы.
	double ** simplex_matrix = new double*[NUM];
	for (int i = 0; i < NUM; i++)
	{
		//создаём матрицу по количеству уникальных единиц техники со своими характеристиками + столбец с ограничениями.
		simplex_matrix[i] = new double[TA_size + AC_size + MR_size + AR_size + FP_size + 1];

		switch (i)
		{
		case 0: // заполнение первой строки симплексной таблицы - стоимость техники и бюджет страны

			tmp = 0;
			simplex_matrix[i][tmp] = country_budget;
			for (int j = 0; j < TA_size; j++) { tmp++; simplex_matrix[i][tmp] = TA[j]->get_cost(); }
			for (int j = 0; j < AC_size; j++) { tmp++; simplex_matrix[i][tmp] = AC[j]->get_cost(); }
			for (int j = 0; j < MR_size; j++) { tmp++; simplex_matrix[i][tmp] = MR[j]->get_cost(); }
			for (int j = 0; j < AR_size; j++) { tmp++; simplex_matrix[i][tmp] = AR[j]->get_cost(); }
			for (int j = 0; j < FP_size; j++) { tmp++; simplex_matrix[i][tmp] = FP[j]->get_cost(); }

			break;
		case 1: // стоимость хранения техники и бюджет для хранения техники

			tmp = 0;
			simplex_matrix[i][tmp] = storage_budget;
			for (int j = 0; j < TA_size; j++) { tmp++; simplex_matrix[i][tmp] = TA[j]->get_storage_cost(); }
			for (int j = 0; j < AC_size; j++) { tmp++; simplex_matrix[i][tmp] = AC[j]->get_storage_cost(); }
			for (int j = 0; j < MR_size; j++) { tmp++; simplex_matrix[i][tmp] = MR[j]->get_storage_cost(); }
			for (int j = 0; j < AR_size; j++) { tmp++; simplex_matrix[i][tmp] = AR[j]->get_storage_cost(); }
			for (int j = 0; j < FP_size; j++) { tmp++; simplex_matrix[i][tmp] = FP[j]->get_storage_cost(); }

			break;
		case 2: // территория военной базы и место, занимаемое техникой на территории.

			tmp = 0;
			simplex_matrix[i][tmp] = military_base_territory;
			for (int j = 0; j < TA_size; j++) { tmp++; simplex_matrix[i][tmp] = TA[j]->get_occupied_space(); }
			for (int j = 0; j < AC_size; j++) { tmp++; simplex_matrix[i][tmp] = AC[j]->get_occupied_space(); }
			for (int j = 0; j < MR_size; j++) { tmp++; simplex_matrix[i][tmp] = MR[j]->get_occupied_space(); }
			for (int j = 0; j < AR_size; j++) { tmp++; simplex_matrix[i][tmp] = AR[j]->get_occupied_space(); }
			for (int j = 0; j < FP_size; j++) { tmp++; simplex_matrix[i][tmp] = FP[j]->get_occupied_space(); }

			break;
		case 3: // огневая мощь армии + огневая мощь каждой единицы техники (берём с отрицательным знаком).

			tmp = 0;
			simplex_matrix[i][tmp] = requirement_power;
			for (int j = 0; j < TA_size; j++) { tmp++; simplex_matrix[i][tmp] = -TA[j]->get_firepower(); }
			for (int j = 0; j < AC_size; j++) { tmp++; simplex_matrix[i][tmp] = -AC[j]->get_firepower(); }
			for (int j = 0; j < MR_size; j++) { tmp++; simplex_matrix[i][tmp] = -MR[j]->get_firepower(); }
			for (int j = 0; j < AR_size; j++) { tmp++; simplex_matrix[i][tmp] = -AR[j]->get_firepower(); }
			for (int j = 0; j < FP_size; j++) { tmp++; simplex_matrix[i][tmp] = -FP[j]->get_firepower(); }

			break;
		default:
			break;
		}
	}

	double * result = new double[TA_size + AC_size + MR_size + AR_size + FP_size];
	Simplex * Power = new Simplex(simplex_matrix, NUM, TA_size + AC_size + MR_size + AR_size + FP_size + 1);
	requirement_power = Power->Calculate(result);
	tmp = NULL;
	for (int i = 0; i < TA_size; i++) { TA[i]->set_number_in_the_army((int)result[tmp]); tmp++; }
	for (int i = 0; i < AC_size; i++) { AC[i]->set_number_in_the_army((int)result[tmp]); tmp++; }
	for (int i = 0; i < MR_size; i++) { MR[i]->set_number_in_the_army((int)result[tmp]); tmp++; }
	for (int i = 0; i < AR_size; i++) { AR[i]->set_number_in_the_army((int)result[tmp]); tmp++; }
	for (int i = 0; i < FP_size; i++) { FP[i]->set_number_in_the_army((int)result[tmp]); tmp++; }


	for (int i = 0; i < NUM; i++) { delete[] simplex_matrix[i]; }
	delete simplex_matrix;
	delete Power;
	delete[] result;
}

Army::~Army()
{
	delete[] TA;
	delete[] AC;
	delete[] MR;
	delete[] AR;
	delete[] FP;
}
