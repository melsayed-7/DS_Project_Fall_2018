#include "Fighter.h"






Fighter::Fighter(color r_c, int id, int Arraival_Time, double health, double Power, REGION r_region, int d, int reload) : Enemy(r_c, r_region, d, reload)
{
	ID = id;
	arraival_time = Arraival_Time;
	Health = health;
	power = Power;
}


Fighter::~Fighter(void)
{
}

void Fighter::Act()
{
	
	int k=0;
	if(Health>fighter_health/2)  k=1;
	
	else   k=0.5;
		
	double healt_deducted =target->GetHealth() - (k / Distance)*get_power();
	target->SetHealth(healt_deducted);
	
}


bool Fighter::is_frozen()
{
	return frozen;
}

void Fighter::Move()
{
	if(!is_frozen())
	{
		DecrementDist(); // The frozern cannot shoot only but can move.
	}
}

void Fighter::set_target(Tower* Tower)
{
	target = Tower;
}