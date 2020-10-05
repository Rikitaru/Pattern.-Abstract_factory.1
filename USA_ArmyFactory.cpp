#include "USA_ArmyFactory.h"

Tank * USA_ArmyFactory::create_Tank()
{
	return new USA_Tank;
}

Armored_carrier * USA_ArmyFactory::create_Armored_carrier()
{
	return new USA_Armored_carrier;
}

Military_robot * USA_ArmyFactory::create_Military_robot()
{
	return new USA_Military_robot;
}

Artillery * USA_ArmyFactory::create_Artillery()
{
	return new USA_Artillery;
}

Fighter_plane * USA_ArmyFactory::create_Fighter_plane()
{
	return new USA_Fighter_plane;
}