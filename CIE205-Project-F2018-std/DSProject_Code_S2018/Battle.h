#pragma once

#include "Fighter.h"
#include "Healer.h"
#include "Freezer.h"
#include "Castle\Castle.h"
#include "Data_strutres_in_use/Queue/Queue.h"


// it is the controller of the project
class Battle
{
private:
	Castle BCastle;
	int EnemyCount;	//the actual number of enemies in the game
	Enemy * BEnemiesForDraw[MaxEnemyCount]; // This Array of Pointers is used for drawing elements in the GUI
								  			// No matter what list type you are using to hold enemies,
											// you must pass the enemies to the GUI function as an array of enemy pointers.
											// At every time step, you should update those pointers
											// to point to the current active enemies
											// then pass the pointers list to the GUI function

	//
	// TODO: Add More Data Members As Needed
	//

public:

	Battle();
	void AddEnemy(Enemy* Ptr);
	void ClearEnemy();
	Castle * GetCastle();
	void RunSimulation();
	void set_initlailized_castle(double health,int no_enemies, double power);
	void phase2_simulation();	//just to show a demo and should be removed in phase1 1 & 2
	int compute_priority(Enemy* ptr);
	Queue <Enemy*>*fill_inactivelist(Queue <int*>* Data);	//the array that creates the objects based on the readnings of the file
	Queue <Enemy*>*killed_enemies = new Queue <Enemy*>;//a queue that holds pointer to enemies
	//Queue <Enemy*>* get_killed_enemies();
	//
	// TODO: Add More Member Functions As Needed
	//
};
