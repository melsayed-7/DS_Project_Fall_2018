#pragma once
#include "Enemies/Enemy.h"
class Melter : public Enemy
{
public:
	Enemy* target;

	Melter(color r_c, REGION r_region, int d, int reload);
	Melter(color r_c, int id, int Arraival_Time, double health, double Power, REGION r_region, int d, int reload);
	~Melter(void);
	virtual void Act();
	virtual void Move();
	virtual bool is_frozen();
	void set_target(Tower* tower);
	virtual void set_visible(bool visible_bool);
	virtual bool get_visible();
};

