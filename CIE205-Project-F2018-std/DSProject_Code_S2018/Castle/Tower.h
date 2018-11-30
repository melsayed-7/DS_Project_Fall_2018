#pragma once
#include "..\Defs.h"
class Tower
{
	double Health;
	double ice;
	double ice_to_freeze;
	bool frozen;
	int frozen_period;
	bool killed;


	//
	// TODO: Add More Data Members As Needed
	//

public:

	Tower();
	void SetHealth(double h);
	double GetHealth() const;
	void increment_ice(double ice_added);


	//
	// TODO: Add More Member Functions As Needed
	//

};

