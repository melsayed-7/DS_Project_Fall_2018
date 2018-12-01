#include "Castle.h"
#include "..\GUI\GUI.h"

Castle::Castle()
{
}

void Castle::SetTowerHealth(REGION TowerRegion, double h)
{
		Towers[TowerRegion].SetHealth(h);	
}

double Castle::get_total_tower_health()
{
	return Towers[0].GetHealth()+ Towers[1].GetHealth() + Towers[2].GetHealth() + Towers[3].GetHealth();
}



void Castle::set_all_towers(double health, int no_enemies, int power)
{
	for (int i = 0; i < NoOfRegions; i++)
	{
		Towers[i].SetHealth(health);
		Towers[i].Setmax_enemies(no_enemies);
		Towers[i].Set_power(power);
	}
}


void Castle::tower_act(int tower_number, Enemy* enemy)
{
	int index = tower_number - 1;
	int distance = enemy->GetDistance();
	double tower_power = Towers[index].get_power();
	int type = enemy->get_type();
	int k = 0;
	if (type == 1 || type == 3) k = 1;
	else k = 0.5;
	
	double health_deducted =(1/distance)*(tower_power)*(1/k);


	enemy->set_health((enemy->get_health()) - health_deducted);   // deduct some health of the enemy;
}


