#pragma once
#include "Army.h"

// Здесь создается армия той или иной стороны
class Cold_war
{
public:
	Army * createArmy(ArmyFactory& factory);
};

