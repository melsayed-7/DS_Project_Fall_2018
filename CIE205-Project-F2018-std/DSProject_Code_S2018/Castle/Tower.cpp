#include "Tower.h"


Tower::Tower()
{
	SetHealth(TowerInitHealth);
	ice = 0;
	ice_to_freeze = 20;
	frozen = false;
	frozen_period = 3;
	
}

Tower::Tower(double health, int no_enemies, double TPower)
{
	Health = health;
	max_enemies = no_enemies;
	power = TPower;
}





void Tower::SetHealth(double h)
{
	if(h > 0)
		Health = h;
	else
		Health = 0; // killed

	if (Health <= 0)
	{
		Health = 0;
		killed = true;
	}
}

void Tower::Setmax_enemies(int h)
{
	// maximum of enemis to be targeted by the the tower
	if (h > 0)
		max_enemies = h;
	else
		max_enemies = 3;
}

void Tower::Set_power(double h)
{
	if (h > 0)
		power = h;
	else
		power = 300;
}


double Tower::GetHealth() const
{
	return Health;
}

void Tower::increment_ice(double ice_added)
{
	//ice to be added to freeze the tower
	ice = ice + ice_added;
	
	if (ice >= ice_to_freeze)
	{
		ice = 0;
		frozen = true;
	}
}


double Tower::get_power()
{
	return power;
}