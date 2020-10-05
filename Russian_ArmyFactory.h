#pragma once
#include "ArmyFactory.h"
#include "Russian_Tank.h"
#include "Russian_Armored_carrier.h"
#include "Russian_Military_robot.h"
#include "Russian_Artillery.h"
#include "Russian_Fighter_plane.h"

class Russian_ArmyFactory :	public ArmyFactory
{
public:
	Tank * create_Tank();
	Armored_carrier* create_Armored_carrier(); 
	Military_robot* create_Military_robot();
	Artillery* create_Artillery();
	Fighter_plane* create_Fighter_plane();
};

