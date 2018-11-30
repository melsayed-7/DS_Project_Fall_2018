#include "Healer.h"


Healer::Healer(color r_c, REGION r_region, int d, int reload):Enemy( r_c,  r_region,d, reload)
{
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
	if(!is_frozen())
	{
		DecrementDist();
	}
}

bool Healer::is_frozen()
{
	return frozen;
}

void Healer::set_target(Enemy* Target[MaxEnemyCount])
{

}