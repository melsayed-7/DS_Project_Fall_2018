#pragma once
#pragma once
#include "Enemies/Enemy.h"
#include "Castle/Tower.h"

class Vanisher : public Enemy
{
private:
	Tower* target;

public:
	//Vanisher(color r_c, REGION r_region, int d, int reload);
	Vanisher(color r_c, int id, int arraival_time, double health, double power, REGION r_region, int d, int reload);
	~Vanisher(void);
	void Act();
	virtual void Move();
	virtual bool is_frozen();
	void set_target(Tower* Tower);
	virtual void set_visible(bool visible_bool);
	virtual bool get_visible();
};

