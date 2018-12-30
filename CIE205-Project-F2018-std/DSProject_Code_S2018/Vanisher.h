#pragma once
#include "Enemies/Enemy.h"
#include "Castle/Tower.h"

class Vanisher : public Enemy
{
private:
	Tower* target;
	int vanishing_time;

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
	virtual void set_vanishing_time(int vt);
	virtual void increment_vanishing_time();
	virtual int get_vanishing_time();
};

