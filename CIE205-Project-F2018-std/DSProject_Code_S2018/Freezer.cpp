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
		
}

void Freezer::Move()
{
	if(!is_frozen())
	{
		DecrementDist();
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