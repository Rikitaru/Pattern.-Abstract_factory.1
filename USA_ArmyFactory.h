#pragma once
#include "ArmyFactory.h"
#include "USA_Tank.h"
#include "USA_Armored_carrier.h"
#include "USA_Military_robot.h"
#include "USA_Artillery.h"
#include "USA_Fighter_plane.h"

class USA_ArmyFactory : public ArmyFactory
{
public:
	Tank * create_Tank();
	Armored_carrier* create_Armored_carrier();
	Military_robot* create_Military_robot();
	Artillery* create_Artillery();
	Fighter_plane* create_Fighter_plane();
};

