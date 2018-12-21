#include "Healer.h"


Healer::Healer(color r_c, REGION r_region, int d, int reload):Enemy( r_c,  r_region,d, reload)
{
}

Healer::Healer(color r_c, int id, int Arraival_Time, double health, double Power, REGION r_region, int d, int reload) : Enemy(r_c, r_region, d, reload)
{
	ID = id;
	arraival_time = Arraival_Time;
	Health = health;
	power = Power;
	type = 2;
}

Healer::~Healer(void)
{
}


void Healer::Act()
{
	// here we will refill some health for nearby enemies

}


void Healer::Move()
{
	if (freeze_period == 0)
	{
		frozen = false;
	}

	// decrementing the distance depending on the frozen state
	if (!is_frozen())
	{
		DecrementDist(); // The frozern cannot shoot only but can move.
	}
	else // if it is frozen
	{
		freeze_period--;
	}
}

bool Healer::is_frozen()
{
	return frozen;
}

void Healer::set_target(Tower* tower)
{
	// until the next phase
}