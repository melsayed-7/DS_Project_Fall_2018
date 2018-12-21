#include "Healer.h"
#include <math.h>


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
	int size = my_heap->get_size();
	Enemy** array = new Enemy*[size];

	for (int i = 0; i < size; i++)
	{
	array[i] = my_heap->Dequeue();
	}

	for (int i = 0; i < size; i++)
	{
		  my_heap->Enqueue(compute_priority(array[i]),array[i]);
	}


	for (int i = 0; i < size; i++)
	{
		if (abs(array[i]->GetDistance() - Distance)<=2)
		{
			array[i]->set_health(-5);
		}
	}
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

void Healer::set_target(Tower* tower)
{
	// until the next phase
}