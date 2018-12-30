#include "Castle.h"
#include "..\GUI\GUI.h"
#include <math.h>
#include <ctime>
#include <cstdlib>
Castle::Castle()
{
	srand(time(NULL));
}

void Castle::SetTowerHealth(REGION TowerRegion, double h)
{
	Towers[TowerRegion].SetHealth(h);
}

double Castle::get_total_tower_health()
{
	// summing all the tower healthes to know when to close the simulation in case the ememy won
	return Towers[0].GetHealth() + Towers[1].GetHealth() + Towers[2].GetHealth() + Towers[3].GetHealth();
}



void Castle::set_all_towers(double health, int no_enemies, int power)
{
	// defining the health and enemy range and power of each tower.
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i].SetHealth(health);
		Towers[i].Setmax_enemies(no_enemies);
		Towers[i].Set_power(power);
	}
}


void Castle::tower_act(int tower_number, Enemy* enemy, int current_tick)
{
	// the tower attacking the enemies and deducting health
	if (enemy->get_visible()& !Towers[tower_number].is_frozen())  //enemy->get_visible()
	{
		int index = tower_number;
		int distance = enemy->GetDistance();
		double tower_power = Towers[index].get_power();
		int type = enemy->get_type();

		int random = rand() % 100;

		if (enemy->is_shot_before())
		{
			enemy->set_shot_before();//record that he was already shoted
			enemy->set_FD(current_tick - 1 - (enemy->get_arraival_time()));
			enemy->set_tfirst_shot(current_tick - 1);
		}


		if (random < 20 && !enemy->is_frozen()) // if the perscentage was 20% (freeze) and the enemy is not already frozen
		{
			enemy->Freeze();

		}

		else
		{
			// defining the constant k in the equation of the effect of the tower on the enemy
			double k = 0;
			if (type == 1 || type == 3) k = 1;
			else k = 0.5;

			double health_deducted = (1.0 / distance)*(tower_power)*(1 / k);

			if (!Towers[index].is_frozen())
			{
				enemy->set_health(health_deducted);   // deduct some health of the enemy;
				Towers[index].set_frozen(false);
			}


		}
	}
	Towers[tower_number].set_frozen(0);
	

}


Tower* Castle::get_tower(int index)
{
	return &Towers[index];
}

void Castle::reconstruct_towers()
{
	double health_after_reconstruction = get_total_tower_health() / 4;
	
		if (Towers[0].GetHealth() == 0 || Towers[1].GetHealth() == 0 || Towers[2].GetHealth() == 0 || Towers[3].GetHealth() == 0)
		{
			for (int i = 0; i < 4; i++) {

			Towers[i].SetHealth(health_after_reconstruction);
		}	
	}
}

