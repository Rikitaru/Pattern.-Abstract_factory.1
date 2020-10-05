#pragma once
#include "Tank.h"
#include "Armored_carrier.h"
#include "Military_robot.h"
#include "Artillery.h"
#include "Fighter_plane.h"

class ArmyFactory
{
public:
	virtual Tank* create_Tank() = 0;
	virtual Armored_carrier* create_Armored_carrier() = 0;
	virtual Military_robot* create_Military_robot() = 0;
	virtual Artillery* create_Artillery() = 0;
	virtual Fighter_plane* create_Fighter_plane() = 0;
	virtual ~ArmyFactory() {}
};