#include "Cold_war.h"

Army * Cold_war::createArmy(ArmyFactory & factory)
{
	Army* p = new Army;
	p->initialization();
	for (int i = 0; i < p->TA_size; ++i)  p->TA[i] = factory.create_Tank();
	for (int i = 0; i < p->AC_size; ++i)  p->AC[i] = factory.create_Armored_carrier();
	for (int i = 0; i < p->MR_size; ++i)  p->MR[i] = factory.create_Military_robot();
	for (int i = 0; i < p->AR_size; ++i)  p->AR[i] = factory.create_Artillery();
	for (int i = 0; i < p->FP_size; ++i)  p->FP[i] = factory.create_Fighter_plane();
	return p;
}
