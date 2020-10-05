#include "Russian_ArmyFactory.h"

Tank * Russian_ArmyFactory::create_Tank()
{
	return new Russian_Tank;
}

Armored_carrier * Russian_ArmyFactory::create_Armored_carrier()
{
	return new Russian_Armored_carrier;
}

Military_robot * Russian_ArmyFactory::create_Military_robot()
{
	return new Russian_Military_robot;
}

Artillery * Russian_ArmyFactory::create_Artillery()
{
	return new Russian_Artillery;
}

Fighter_plane * Russian_ArmyFactory::create_Fighter_plane()
{
	return new Russian_Fighter_plane;
}