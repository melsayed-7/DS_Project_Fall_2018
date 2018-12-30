#include "Melter.h"
#include <math.h>


Melter::Melter(color r_c, REGION r_region, int d, int reload) :Enemy(r_c, r_region, d, reload)
{
}

Melter::Melter(color r_c, int id, int Arraival_Time, double health, double Power, REGION r_region, int d, int reload) : Enemy(r_c, r_region, d, reload)
{
	ID = id;
	arraival_time = Arraival_Time;
	Health = health;
	power = Power;
	type = 4;
}

Melter::~Melter(void)
{
}


void Melter::Act()
{
	int size = my_heap->get_size();
	Enemy** array = new Enemy*[size];

	for (int i = 0; i < size; i++)
	{
		array[i] = my_heap->Dequeue();
	}

	for (int i = 0; i < size; i++)
	{
		if (abs(array[i]->GetDistance() - Distance) <= 2 && array[i] != this)
		{
			array[i]->set_frozen(0);
		}
	}

	for (int i = 0; i < size; i++)
	{
		my_heap->Enqueue(compute_priority(array[i]), array[i]);
	}
}

void Melter::Move()
{
	if (!is_frozen())
	{
		DecrementDist();
	}
}

bool Melter::is_frozen()
{
	return frozen;
}

void Melter::set_target(Tower* tower)
{
	// until the next phase
}

void Melter::set_visible(bool visible_bool) {
	
}

bool Melter::get_visible() {
	return visible;
}