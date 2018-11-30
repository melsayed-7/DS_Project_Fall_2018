#include "Tower.h"


Tower::Tower()
{
	SetHealth(TowerInitHealth);
	ice = 0;
	ice_to_freeze = 20;
	frozen = false;
	frozen_period = 3;
	
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

double Tower::GetHealth() const
{
	return Health;
}

void Tower::increment_ice(double ice_added)
{
	ice = ice + ice_added;
	
	if (ice >= ice_to_freeze)
	{
		ice = 0;
		frozen = true;
	}
}