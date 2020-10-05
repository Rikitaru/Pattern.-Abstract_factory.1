#pragma once
#include "Tank.h"
#include "Exception.h"

class Russian_Tank : public Tank
{
	char name[20];
	int cost;
	int storage_cost;
	int occupied_space;
	int firepower;
	int number_in_the_army;

public:
	virtual void set_name(char * _name);
	virtual void set_cost(int _cost);
	virtual void set_storage_cost(int _storage_cost);
	virtual void set_occupied_space(int _occupied_space);
	virtual void set_firepower(int _firepower);

	char* get_name();
	int get_cost();
	int get_storage_cost();
	int get_occupied_space();
	int get_firepower();
	int get_number_in_the_army();

	void set_number_in_the_army(int _number_in_the_army);
	void set();
	void info();
};

