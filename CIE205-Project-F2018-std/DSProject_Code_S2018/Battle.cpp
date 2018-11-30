#include "Battle.h"
#include "File_IO.h"
#include "Data_strutres_in_use/Queue/Queue.h"
#include <iostream>

Battle::Battle()
{
	EnemyCount = 0;
}

void Battle::AddEnemy(Enemy* Ptr)
{
	if (EnemyCount < MaxEnemyCount)
	{
		BEnemiesForDraw[EnemyCount++] = Ptr;
	}


	// Note that this function doesn't allocate any enemy objects
	// It only makes the first free pointer in the array
	// points to the same enemy pointed to by "Ptr"
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
	Just_A_Demo();
}


//This is just a demo function for project introductory phase
//It should be removed in phases 1&2
void Battle::Just_A_Demo()
{
	Queue<int*>*Data = new  Queue<int*>;

	Data = get_file_2_queue();//enter the name of the file here;

	int *dummyarr = Data->deque();//the first line has the twor data

	double TH = dummyarr[0];//tower health
	int max_enemies = dummyarr[1];//number of enemies attacked per second
	double TP = dummyarr[2];//tower power


	set_initlailized_castle(TH, max_enemies, TP);


	int enemy_id;
	int type;
	int arrival_time;
	int health;
	int pow;
	int reload;
	int region;


	Fighter * fighter;
	Healer * healer;
	Freezer * freezer;

	Queue <Enemy*>*inactive_queue = new Queue <Enemy*>;//a queue that holds apointer to enemies

	for (int i = 0; i < Data->getsize(); i++)
	{
		dummyarr = Data->deque();//the first line has the twor data	
		enemy_id = dummyarr[0];
		type = dummyarr[1];
		arrival_time = dummyarr[2];
		health = dummyarr[3];
		pow = dummyarr[4];
		reload = dummyarr[5];
		region = dummyarr[6];
		
		switch (type)
		{
		case 1://fighter
			fighter = new Fighter(FIGHTER_CLR, enemy_id, arrival_time,health,pow, A_REG, 6, 3);
			inactive_queue->enque(fighter);
			break;
		case 2://healer
			healer = new Healer(HEALER_CLR, enemy_id, arrival_time, health, pow, A_REG, 6, 3);
			inactive_queue->enque(healer);
			break;
		case 3://freezer
			freezer = new Freezer(FREEZER_CLR, enemy_id, arrival_time, health, pow, A_REG, 6, 3);
			inactive_queue->enque(freezer);
			break;
		}
	}


	std::cout << "\nWelcome to Castle Battle:\n";
	std::cout << "\nIn phase2, you will be asked to select game mode\n";
	std::cout << "\nFor now just press ENTER key to continue...";

	char tmp[10];
	std::cin.getline(tmp, 10);
	//
	// THIS IS JUST A DEMO
	// IT SHOULD BE REMOVED IN PHASE 1 AND PHASE 2
	//

	GUI * pGUI = new GUI;

	pGUI->PrintMessage("This is Just a Demo. It should be changed ib phase1 & phase2. Click to move to next step");



	// Declare some enemies and fill their data
	// In the game, enemies should be loaded from an input file
	// and should be dynamically allocated
	/*
	Fighter e1(DARKBLUE, A_REG, 6, 3);
	Fighter e2(DARKBLUE, D_REG, 60, 3);
	Fighter e3(DARKOLIVEGREEN, B_REG, 60, 3);
	Fighter e4(DARKOLIVEGREEN, A_REG, 4, 3);
	Fighter e5(ORANGERED, C_REG, 19, 3);
	Fighter e6(ORANGERED, C_REG, 30, 3);
	Fighter e7(ORANGERED, A_REG, 2, 3);
	Fighter e8(DARKOLIVEGREEN, C_REG, 7, 3);
	Fighter e9(ORANGERED, A_REG, 30, 3);
	Fighter e10(DARKBLUE, C_REG, 4, 3);
	Healer e11(GREEN, A_REG, 20, 3);
	

	// Adding the enemies to the battle
	AddEnemy(&e1);
	AddEnemy(&e2);
	AddEnemy(&e3);
	AddEnemy(&e4);
	AddEnemy(&e5);
	AddEnemy(&e6);
	AddEnemy(&e7);
	AddEnemy(&e8);
	AddEnemy(&e9);
	AddEnemy(&e10);
	AddEnemy(&e11);
	

	// Drawing the battle
	pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);

	Point p;
	pGUI->GetPointClicked(p);

	// Now a demo to move enemies some time steps
	// TimeStep is a normal integer that is incremented each time by 1
	for (int TimeStep = 1; TimeStep <= 30; TimeStep++)
	{

		// Decrement the distance of each enemy. Just for the sake of demo
		e1.DecrementDist();
		e2.DecrementDist();
		e3.DecrementDist();
		e4.DecrementDist();
		e5.DecrementDist();
		e6.DecrementDist();
		e7.DecrementDist();
		e8.DecrementDist();
		e9.DecrementDist();
		e10.DecrementDist();

		// Redraw the enemies
		pGUI->DrawBattle(BEnemiesForDraw, EnemyCount);

		pGUI->GetPointClicked(p);
	}
	*/
	delete pGUI;
}