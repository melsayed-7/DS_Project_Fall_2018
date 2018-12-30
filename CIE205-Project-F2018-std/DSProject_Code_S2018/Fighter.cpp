#include "Fighter.h"






Fighter::Fighter(color r_c, int id, int Arraival_Time, double health, double Power, REGION r_region, int d, int reload) : Enemy(r_c, r_region, d, reload)
{
	ID = id;
	arraival_time = Arraival_Time;
	Health = health;
	power = Power;
	type = 1;
}


Fighter::~Fighter(void)
{
}

void Fighter::Act()
{	
	// defining the constant k of the equation depending on the health of the fighter
	double k=0;					
	if (Health > fighter_health / 2)  k = 1;
	else   k=0.5;
		
	double healt_deducted =target->GetHealth()-(k / Distance)*get_power();    // this will be the new health of the tower
	target->SetHealth(healt_deducted);			// calling set health function of the target tower
	
}


bool Fighter::is_frozen()
{
	return frozen;
}

void Fighter::Move()
{
	if (freeze_period == 0)
	{
		frozen = false;
	}

	// decrementing the distance depending on the frozen state
	if(!is_frozen())
	{
		DecrementDist(); // The frozern cannot shoot only but can move.
	}
	else // if it is frozen
	{
		freeze_period--;
	}
}

void Fighter::set_target(Tower* Tower) // defining the target tower
{
	target = Tower;
}

void Fighter::set_visible(bool visible_bool) {
	
}

bool Fighter::get_visible() {
	return visible;
}

void Fighter::set_vanishing_time(int vt)
{
}

void Fighter::increment_vanishing_time()
{
}

int Fighter::get_vanishing_time()
{
	return 0;
}
