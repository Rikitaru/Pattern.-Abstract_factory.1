#pragma once
#include "Header.h"
#include "Tank.h"
#include "Armored_carrier.h"
#include "Military_robot.h"
#include "Artillery.h"
#include "Fighter_plane.h"
#include "Exception.h"
#include "ArmyFactory.h"
#include "Simplex.h"

// Класс, содержащий всех воинов той или иной армии
class Army
{
	friend class Cold_war;
private:

	//уникальная техника
	Tank ** TA;
	Armored_carrier** AC;
	Military_robot** MR;
	Artillery** AR;
	Fighter_plane** FP;

	//количество уникальной техники
	int TA_size;
	int AC_size;
	int MR_size;
	int AR_size;
	int FP_size;

	//Ресурсы страны
	int country_budget;
	int storage_budget;
	int military_base_territory;
	int requirement_power;

public:

	Army();
	int get_requirement_power();
	void initialization();
	void set();
	void info();
	void save_to_file(const char * filename);
	void read_from_file(const char * filename, ArmyFactory& factory);
	void Who_is_more_powerful(void);
	~Army();

};

