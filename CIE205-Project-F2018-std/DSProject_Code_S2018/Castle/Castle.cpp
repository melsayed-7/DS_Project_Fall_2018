#include "Castle.h"
#include "..\GUI\GUI.h"

Castle::Castle()
{
}

void Castle::SetTowerHealth(REGION TowerRegion, double h)
{
		Towers[TowerRegion].SetHealth(h);	
}



void Castle::set_all_towers(double health, int no_enemies, int power)
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i].SetHealth(health);
		Towers[i].Setmax_enemies(no_enemies);
		Towers[i].Set_power(power);
	}
}