#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Castle\Tower.h"
#include "..\Data_strutres_in_use\heap\Heap.h"

//Enemies colors for next phases
//You can choose whatever colors you like for your enemies
const color FIGHTER_CLR = DARKRED;
const color HEALER_CLR = LIGHTGREEN;
const color FREEZER_CLR = ICEBLUE;
const color MELTER_CLR = ORCHID;
const color DEAD_CLR = GREY;

// Enemy is the base class of each type of enemy
// Enemy should be an abstract class in next phases
class Enemy
{

protected:
	int ID;         //Each enemy has a unique ID (sequence number)
	color Clr;	    //Color of the enemy (will be set depending on the enemy type: Paver, ...etc.)
	REGION Region;  //Region of this enemy
	int Distance;	//Horizontal distance between enemy & the tower of its region
	                //Always positive (ranges from 2 to 60)
	double Health;	//Enemy health
	double power;

	int type;		

	int reload_period;
	int freeze_period;
	bool killed;
	bool frozen;
	bool active;

	int arraival_time;

	// statistics varible
	int KTS;//killed time step
	int FD; // first shot delay
	int KD;//killed delay
	int LT;//lifetime
	int tfirst_shot;
	bool shot_before;



	Heap<Enemy*>* my_heap;

	//
	// TODO: Add More Data Members As Needed
	//

public:
	Enemy();
	Enemy( color r_c, REGION r_region, int d = MaxDistance, int reload = 3);
	virtual ~Enemy();

	color GetColor() const;
	REGION GetRegion() const;
	
	// some function used in fighting logic 
	void DecrementDist();
	int get_arraival_time();
	void SetDistance(int d);
	int GetDistance() const;
	double get_health();
	void set_health(double health_deducted);
	double get_power();
	void take_heap(Heap<Enemy*>* enemy_heap);
	
	void set_FD(int d);
	void set_KD(int d);
	void set_KTS(int d);
	void set_LT();
	void set_tfirst_shot(int d);

	int get_FD();
	int get_KD();
	int get_KTS();
	int get_LT();
	int get_tfirst_shot();
	bool is_shot_before();
	void set_shot_before();

	int get_type();
	bool is_killed();
	void Freeze();
	// Virtual Functions: ----------------

	virtual void Move() = 0;	//All enemies can move
	virtual void Act() = 0;		//Acting means fighting or healing
	virtual bool is_frozen() = 0;
	virtual void set_target(Tower* tower) = 0;
	int compute_priority(Enemy* ptr);
	void set_frozen(bool frozen_bool);

	//
	// TODO: Add More Member Functions As Needed
	//

};

