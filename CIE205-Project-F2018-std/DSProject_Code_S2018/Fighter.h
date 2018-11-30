#pragma once
#include "Enemies/Enemy.h"
#include "Castle/Tower.h"

class Fighter : public Enemy
{
private:
	Tower* target;

public:
	Fighter(color r_c, REGION r_region, int d, int reload);
	~Fighter(void);
	void Act();
	virtual void Move();
	virtual bool is_frozen();
	void set_target(Tower* Tower);
};

