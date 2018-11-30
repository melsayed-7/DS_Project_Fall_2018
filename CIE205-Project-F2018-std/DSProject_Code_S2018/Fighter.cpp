#include "Fighter.h"


Fighter::Fighter(color r_c, REGION r_region, int d,int reload):Enemy( r_c,  r_region,d)
{
	reload_period= reload;
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
		DecrementDist();
	}
}

void Fighter::set_target(Tower* Tower)
{
	target = Tower;
}