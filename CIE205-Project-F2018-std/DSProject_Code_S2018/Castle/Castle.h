#pragma once

#include "..\Defs.h"
#include "..\CMUgraphicsLib\CMUgraphics.h"
#include "..\GUI\GUI.h"

#include "Tower.h"

class Castle
{

	Tower Towers[NoOfRegions];

	//
	// TODO: Add More Data Members As Needed
	//
	
public:

	Castle();
	//Castle(double TH, int no_enemies, double power);
	void SetTowerHealth(REGION TowerRegion, double h);
	double get_total_tower_health();
	void set_all_towers(double health, int no_enemies, int power);

	//
	// TODO: Add More Member Functions As Needed
	//
};




