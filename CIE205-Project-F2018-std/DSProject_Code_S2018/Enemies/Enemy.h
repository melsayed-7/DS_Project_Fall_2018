#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\Castle\Tower.h"

//Enemies colors for next phases
//You can choose whatever colors you like for your enemies
const color FIGHTER_CLR = DARKRED;
const color HEALER_CLR = LIGHTGREEN;
const color FREEZER_CLR = ICEBLUE;
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
	bool killed;
	bool frozen;
	bool active;

	int arraival_time;

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

	int get_type();
	bool is_killed();
	// Virtual Functions: ----------------

	virtual void Move() = 0;	//All enemies can move
	virtual void Act() = 0;		//Acting means fighting or healing
	virtual bool is_frozen() = 0;
	virtual void set_target(Tower* tower) = 0;

	//
	// TODO: Add More Member Functions As Needed
	//

};

