#pragma once
#include "Enemies\Enemy.h"
#include "Castle/Tower.h"
class Freezer :
	public Enemy
{
private:
	Tower* target;

public:
	Freezer(color r_c, REGION r_region, int d);
	~Freezer(void);
	void Act();
	void set_target(Tower* Tower);
	virtual void Move();
	virtual bool is_frozen();

};

