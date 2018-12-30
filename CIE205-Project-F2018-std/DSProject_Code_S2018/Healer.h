#pragma once
#include "Enemies/Enemy.h"
class Healer : 	public Enemy
{
public:
	Enemy* target;

	Healer(color r_c, REGION r_region, int d, int reload);
	Healer(color r_c, int id, int Arraival_Time, double health, double Power, REGION r_region, int d, int reload);
	~Healer(void);
	virtual void Act();
	virtual void Move();
	virtual bool is_frozen();
	void set_target(Tower* tower);
	virtual void set_visible(bool visible_bool);
	virtual bool get_visible();

	virtual void set_vanishing_time(int vt);
	virtual void increment_vanishing_time();
	virtual int get_vanishing_time();

};

