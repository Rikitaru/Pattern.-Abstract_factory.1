#include "USA_Armored_carrier.h"

void USA_Armored_carrier::set_name(char * _name)
{
	strcpy(name, _name);
}

void USA_Armored_carrier::set_cost(int _cost)
{
	cost = _cost;
}

void USA_Armored_carrier::set_storage_cost(int _storage_cost)
{
	storage_cost = _storage_cost;
}

void USA_Armored_carrier::set_occupied_space(int _occupied_space)
{
	occupied_space = _occupied_space;
}

void USA_Armored_carrier::set_firepower(int _firepower)
{
	firepower = _firepower;
}

char * USA_Armored_carrier::get_name()
{
	return name;
}

int USA_Armored_carrier::get_cost()
{
	return cost;
}

int USA_Armored_carrier::get_storage_cost()
{
	return storage_cost;
}

int USA_Armored_carrier::get_occupied_space()
{
	return occupied_space;
}

int USA_Armored_carrier::get_firepower()
{
	return firepower;
}

int USA_Armored_carrier::get_number_in_the_army()
{
	return number_in_the_army;
}

void USA_Armored_carrier::set_number_in_the_army(int _number_in_the_army)
{
	number_in_the_army = _number_in_the_army;
}

void USA_Armored_carrier::set()
{
	Exception ex;
	string text;
	cout << endl << "Российский танк" << endl;
	cout << "Введите название: ";
	cin >> name;
	text = "Введите стоимость: ";						while (ex.is_digit(cost, text)); // исключение
	text = "Введите стоимость хранения : ";				while (ex.is_digit(storage_cost, text)); // исключение
	text = "Введите место, занимаемое в гараже: ";		while (ex.is_digit(occupied_space, text)); // исключение
	text = "Введите огневую мощь: ";					while (ex.is_digit(firepower, text)); // исключение
}

void USA_Armored_carrier::info()
{
	cout << endl << "Russian_Tank" << endl;
	cout << "Назавние \t\t\t" << name << endl;
	cout << "Стоимость\t\t\t" << cost << endl;
	cout << "Стоимость хранения \t\t" << storage_cost << endl;
	cout << "Место, занимаемое в гараже \t" << occupied_space << endl;
	cout << "Огневая мощь \t\t\t" << firepower << endl;
	cout << "Количество на базе \t\t" << number_in_the_army << endl;
}
