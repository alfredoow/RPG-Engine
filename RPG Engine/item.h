#pragma once

#include "stats.h"
#include <string>
#include <typeinfo>

enum ItemType {
	NONE,
	WEAPON,
	ARMOR,
	CONSUMABLE,
	MATERIAL
};

struct ItemData {
	ItemType type = NONE;
	void* data = nullptr;
};

struct Item {
protected:
	unsigned int id = 0;
	std::string name = "";

	ItemData data;
public:
	Item();
	Item(std::string name);

	ItemData getData();

	unsigned int getID();
	std::string getName();
};

#define EMPTY_ITEM 0

struct Weapon : Item {
	int damage = 0;
	Stats stats = {0, 0, 0};

	Weapon(std::string name, int damage, int STR_mod = 0, int DEX_mod = 0, int INT_mod = 0);
};