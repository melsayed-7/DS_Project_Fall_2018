#include "Enemy.h"


Enemy::Enemy()
{
}

Enemy::Enemy( color r_c, REGION r_region, int d, int reload)
{
	
	Clr = r_c;
	Region = r_region;
	SetDistance(d);
	active = false;
	frozen = false;
	killed = false;
	Health = fighter_health;
	power = (1/4)*Health;
	reload_period = reload;

	
}

Enemy::~Enemy()
{
}

color Enemy::GetColor() const
{
	return Clr;
}

REGION Enemy::GetRegion() const
{
	return Region;
}

void Enemy::DecrementDist()
{
	if (Distance > MinDistance)
		Distance--;
}

int Enemy::get_arraival_time()
{
	return arraival_time;
}

void Enemy::SetDistance(int d)
{
	if (d >= MinDistance && d <= MaxDistance)
		Distance = d;
	else
		Distance = MaxDistance;
}

int Enemy::GetDistance() const
{
	return Distance;
}


double Enemy::get_health()
{
	return Health;
}

double Enemy::get_power()
{
	return power;
}