#pragma once
#include "..\Defs.h"
class Tower
{
	double Health;
	double power;
	double ice;
	double ice_to_freeze;
	bool frozen;
	int frozen_period;
	bool killed;
	int max_enemies;

	//
	// TODO: Add More Data Members As Needed
	//

public:

	Tower();
	Tower(double health, int no_enemies, double TPower);
	void SetHealth(double h);
	double GetHealth() const;
	void increment_ice(double ice_added);
	void Setmax_enemies(int h);
	void Set_power(double h);
	//
	// TODO: Add More Member Functions As Needed
	//

};

