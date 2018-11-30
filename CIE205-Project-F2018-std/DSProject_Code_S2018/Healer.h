#pragma once
#include "Enemies/Enemy.h"
class Healer : 	public Enemy
{
public:
	Enemy* target;

	Healer(color r_c, REGION r_region, int d);
	~Healer(void);
	virtual void Act();
	virtual void Move();
	virtual bool is_frozen();
	void set_target(Enemy* Target [MaxEnemyCount]);
};

