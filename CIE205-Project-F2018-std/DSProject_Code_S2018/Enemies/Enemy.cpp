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
	freeze_period = 0;


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

void Enemy::set_health(double health_deducted)
{
	Health = get_health()- health_deducted;
	if (Health <= 0) killed = true;
}


double Enemy::get_power()
{
	return power;
}

int Enemy::get_type()
{
	return type;
}

bool Enemy::is_killed()
{
	return killed;
}

void Enemy::Freeze()
{
	freeze_period = 3;
	frozen = true;

}

void Enemy::take_heap(Heap<Enemy*>* enemy_heap)
{
	my_heap = enemy_heap;
}


int Enemy::compute_priority(Enemy* ptr)
{
	if (ptr != nullptr)
	{
		double health = ptr->get_health();
		double power = ptr->get_power();
		double distance = ptr->GetDistance();
		return (0.2*health + 0.1*power + 7 / distance + 3);
	}
	else return 0;

}
