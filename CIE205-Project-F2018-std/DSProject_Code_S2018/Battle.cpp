#include "Battle.h"
#include "File_IO.h"
#include "Data_strutres_in_use/Queue/Queue.h"
#include"Castle\Castle.h"
#include "Data_strutres_in_use/heap/Heap.h"
#include <iostream>


Battle::Battle()
{
	EnemyCount = 0;
}

void Battle::AddEnemy(Enemy* Ptr)
{
	if (EnemyCount < MaxEnemyCount)
	{
		if (Ptr != nullptr)
			BEnemiesForDraw[EnemyCount++] = Ptr;
	}

	// Note that this function doesn't allocate any enemy objects
	// It only makes the first free pointer in the array
	// points to the same enemy pointed to by "Ptr"
}


void Battle::ClearEnemy()
{
	for (int i = 0; i < EnemyCount; i++)
	{
		BEnemiesForDraw[EnemyCount] = nullptr;
	}
	EnemyCount = 0;
}

Castle * Battle::GetCastle()
{
	return &BCastle;
}


void Battle::set_initlailized_castle(double health, int no_enemies, double power)
{
	BCastle.set_all_towers(health, no_enemies, power);
}



void Battle::RunSimulation()
{
	phase1_simulation();
}



int Battle::compute_priority(Enemy* ptr)
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



Queue <Enemy*>* Battle::fill_inactivelist(Queue <int*>* Data)
{
	int enemy_id;
	int type;
	int arrival_time;
	int health;
	int pow;
	int reload;
	int region;
	int*dummyarr;
	// Accessing Enemey Classes
	Fighter * fighter;
	Healer * healer;
	Freezer * freezer;

	Queue <Enemy*>*inactive_enemies = new Queue <Enemy*>;//a queue that holds a pointer to enemies
	{
		int intialsize = Data->getsize();
		for (int i = 0; i < intialsize; i++)//fill inactive list
		{
			dummyarr = Data->deque();
			// Set the Tower parameters
			enemy_id = dummyarr[0];
			type = dummyarr[1];
			arrival_time = dummyarr[2];
			health = dummyarr[3];
			pow = dummyarr[4];
			reload = dummyarr[5];
			region = dummyarr[6] - 1;

			REGION reg = A_REG;

			switch (region)
			{
			case 0:
				reg = A_REG;
				break;
			case 1:
				reg = B_REG;
				break;
			case 2:
				reg = C_REG;
				break;
			case 3:
				reg = D_REG;
				break;
			}

			switch (type)
			{
			case 1://fighter
				fighter = new Fighter(FIGHTER_CLR, enemy_id, arrival_time, health, pow, reg, 60, 3);
				inactive_enemies->enque(fighter);

				break;
			case 2://healer
				healer = new Healer(HEALER_CLR, enemy_id, arrival_time, health, pow, reg, 60, 3);
				inactive_enemies->enque(healer);

				break;
			case 3://freezer
				freezer = new Freezer(FREEZER_CLR, enemy_id, arrival_time, health, pow, reg, 60, 3);
				inactive_enemies->enque(freezer);

				break;
			}

		}
	}
	return inactive_enemies;
}

//This is just a demo function for project introductory phase
//It should be removed in phases 1&2
void Battle::phase1_simulation()
{
	Queue<int*>*Data = new  Queue<int*>;

	Data = get_file_2_queue();//enter the name of the file here(optional);

	int *dummyarr = Data->deque();//remove the first line has the tower data 
	double TH = dummyarr[0];//tower health
	int max_enemies = dummyarr[1];//number of enemies attacked per second
	double TP = dummyarr[2];//tower power
	int total_enemies = Data->getsize(); // Get The total number of Enemies to use later

	set_initlailized_castle(TH, max_enemies, TP); //Intialize castle parameters using first line of input file

// intialize queues
	Queue <Enemy*>*inactive_enemies = fill_inactivelist(Data);//a queue that holds a pointer to enemies
	Queue <Enemy*>*killed_enemies = new Queue <Enemy*>;//a queue that holds pointer to enemies

	std::cout << "\nWelcome to Castle Battle:\n";
	std::cout << "\nIn phase2, you will be asked to select game mode\n";
	std::cout << "\nFor now just press ENTER key to continue...";

	double total_tower_health = BCastle.get_total_tower_health();

	GUI * pGUI = new GUI;


	Heap<Enemy*>** Heap1 = new Heap<Enemy*>*[4];
	Heap<Enemy*>** Heap2 = new Heap<Enemy*>*[4];

	int a = inactive_enemies->getsize();

	for (int i = 0; i < 4; i++)
	{
		Heap1[i] = new Heap<Enemy*>(total_enemies);
		Heap2[i] = new Heap<Enemy*>(total_enemies);
	}

	pGUI->PrintMessage("this is phase one simulation");

	int current_tick = 0;

	Heap<Enemy*>** current_heap = Heap1;
	Heap<Enemy*>** to_be_filled_heap = Heap2;
	Heap<Enemy*>** temp_heap;

	int region_index;
	int enemey_priority;
	bool activationflag = true;
	Enemy* current_enemy;

	Enemy** to_be_hit_enemies = new Enemy*[max_enemies];

	Point p;

	int current_heap_number;

	while (killed_enemies->getsize() < total_enemies && total_tower_health != 0)//this loop will end when all the twoers are destroyed or all the enemies are killed
	{
		ClearEnemy();

		activationflag = true;

		while (!inactive_enemies->isEmpty() && activationflag) // this loop takes out all the enemies that should enter the battle ni the curreent tick
		{
			if (inactive_enemies->front()->get_arraival_time() == current_tick)
			{
				region_index = inactive_enemies->front()->GetRegion();
				enemey_priority = compute_priority(inactive_enemies->front());
				current_heap[region_index]->Enqueue(enemey_priority, inactive_enemies->deque());
			}
			else
			{
				activationflag = false;
				current_tick++;
			}
		}


		for (int i = 0; i < 4; i++)//one iteration per tower
		{
			current_heap_number=current_heap[i]->getcurrent_number();
			if (current_heap_number != 0)
			{
				pGUI->GetPointClicked(p);
				for (int j = 0; j < current_heap[i]->getcurrent_number(); j++)
				{
					current_enemy = current_heap[i]->Dequeue();
					to_be_filled_heap[i]->Enqueue(compute_priority(current_enemy), current_enemy);

					current_enemy->set_target(BCastle.get_tower(i));
					current_enemy->Act();

					AddEnemy(current_enemy);

				}

				for (int j = 0; j < max_enemies; j++)
				{

					to_be_hit_enemies[j] = to_be_filled_heap[i]->Dequeue();
					BCastle.tower_act(i, to_be_hit_enemies[j]);


					if (to_be_hit_enemies[j]->is_killed())
					{
						killed_enemies->enque(to_be_hit_enemies[j]);
						//current_heap[i]->Enqueue(0,nullptr);
					}
					else
					{
						current_heap[i]->Enqueue(compute_priority(to_be_hit_enemies[j]), to_be_hit_enemies[j]);
					}
				}
			}
		}

		pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);

		

		temp_heap = current_heap;
		current_heap = to_be_filled_heap;
		to_be_filled_heap - temp_heap;

	}


	delete pGUI;
}
