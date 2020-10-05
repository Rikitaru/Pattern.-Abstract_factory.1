#pragma once

class Armored_carrier
{
public:
	virtual void set_name(char*) = 0;
	virtual void set_cost(int) = 0;
	virtual void set_storage_cost(int) = 0;
	virtual void set_occupied_space(int) = 0;
	virtual void set_firepower(int) = 0;

	virtual char* get_name() = 0;
	virtual int get_cost() = 0;
	virtual int get_storage_cost() = 0;
	virtual int get_occupied_space() = 0;
	virtual int get_firepower() = 0;
	virtual int get_number_in_the_army() = 0;

	virtual void set_number_in_the_army(int) = 0;
	virtual void set() = 0;
	virtual void info() = 0;
	virtual ~Armored_carrier() {}
};