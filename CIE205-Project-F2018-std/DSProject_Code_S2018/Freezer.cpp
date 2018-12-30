#include "Freezer.h"


Freezer::Freezer(color r_c, REGION r_region, int d, int reload):Enemy( r_c,  r_region,d,reload)
{
	
}

Freezer::Freezer(color r_c, int id, int Arraival_Time, double health, double Power, REGION r_region, int d, int reload) : Enemy(r_c, r_region, d, reload)
{
	ID = id;
	arraival_time = Arraival_Time;
	Health = health;
	power = Power;
	type = 3;
}


Freezer::~Freezer(void)
{
}


void Freezer::Act()
{
	if (freeze_period == 0)
	{
		frozen = false;
	}
	if (!frozen && reload_period == 0)
	{
		target->increment_ice(2);
		reload_period = 3;
	}
	if (reload_period != 0)
	{
		reload_period--;
	}
	
}


void Freezer::Move()
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

bool Freezer::is_frozen()
{
	return frozen;
}


void Freezer::set_target(Tower* Tower)
{
	target = Tower;
}

void Freezer::set_visible(bool visible_bool) {
	
}

bool Freezer::get_visible() {
	return visible;
}

void Freezer::set_vanishing_time(int vt)
{
}

void Freezer::increment_vanishing_time()
{
}

int Freezer::get_vanishing_time()
{
	return 0;
}
