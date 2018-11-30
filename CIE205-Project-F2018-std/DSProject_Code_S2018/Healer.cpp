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