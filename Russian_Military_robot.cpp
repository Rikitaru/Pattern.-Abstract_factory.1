#include "Russian_Military_robot.h"

void Russian_Military_robot::set_name(char * _name)
{
	strcpy(name, _name);
}

void Russian_Military_robot::set_cost(int _cost)
{
	cost = _cost;
}

void Russian_Military_robot::set_storage_cost(int _storage_cost)
{
	storage_cost = _storage_cost;
}

void Russian_Military_robot::set_occupied_space(int _occupied_space)
{
	occupied_space = _occupied_space;
}

void Russian_Military_robot::set_firepower(int _firepower)
{
	firepower = _firepower;
}

char * Russian_Military_robot::get_name()
{
	return name;
}

int Russian_Military_robot::get_cost()
{
	return cost;
}

int Russian_Military_robot::get_storage_cost()
{
	return storage_cost;
}

int Russian_Military_robot::get_occupied_space()
{
	return occupied_space;
}

int Russian_Military_robot::get_firepower()
{
	return firepower;
}

int Russian_Military_robot::get_number_in_the_army()
{
	return number_in_the_army;
}

void Russian_Military_robot::set_number_in_the_army(int _number_in_the_army)
{
	number_in_the_army = _number_in_the_army;
}

void Russian_Military_robot::set()
{
	Exception ex;
	string text;
	cout << endl << "���������� ����" << endl;
	cout << "������� ��������: ";
	cin >> name;
	text = "������� ���������: ";						while (ex.is_digit(cost, text)); // ����������
	text = "������� ��������� �������� : ";				while (ex.is_digit(storage_cost, text)); // ����������
	text = "������� �����, ���������� � ������: ";		while (ex.is_digit(occupied_space, text)); // ����������
	text = "������� ������� ����: ";					while (ex.is_digit(firepower, text)); // ����������
}

void Russian_Military_robot::info()
{
	cout << endl << "Russian_Tank" << endl;
	cout << "�������� \t\t\t" << name << endl;
	cout << "���������\t\t\t" << cost << endl;
	cout << "��������� �������� \t\t" << storage_cost << endl;
	cout << "�����, ���������� � ������ \t" << occupied_space << endl;
	cout << "������� ���� \t\t\t" << firepower << endl;
	cout << "���������� �� ���� \t\t" << number_in_the_army << endl;
}