#pragma once

#include "inventory.h"
#include "entity.h"

class Player : public Entity {
public:
	int gold = 0;

	unsigned int level = 1;
	int level_xp = 100;
	int xp = 0;

	Inventory backpack = Inventory(30);

	Player(int max_hp, int x, int y);
};