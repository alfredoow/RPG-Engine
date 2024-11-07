#pragma once

#include "stats.h"
#include <string>
#include <typeinfo>


enum class ItemType {
	NONE,
	WEAPON,
	ARMOR,
	CONSUMABLE,
	MATERIAL
};

enum class ArmorSlot {
	NONE,
	HEAD,
	AMULET,
	CHEST,
	HANDS,
	RINGS,
	LEGS,
	FEET
};

struct ItemData {
	ItemType type = ItemType::NONE;
	void* data = nullptr;
};

struct Item {
protected:
	unsigned int id = 0;
	std::string name = "";
	bool stackable = true;

	ItemData data;
public:
	Item();
	Item(std::string name, bool stackable = true);

	ItemData getData();

	unsigned int getID();
	std::string getName();
	bool isStackable();
};

struct Weapon : Item {
	int damage = 0;
	Stats stats = {0, 0, 0};

	Weapon(std::string name, int damage, int STR_mod = 0, int DEX_mod = 0, int INT_mod = 0);
};

struct Armor : Item {
	ArmorSlot slot = ArmorSlot::NONE;
	int defense = 0;
	Stats stats = { 0, 0, 0 };

	Armor(std::string name, int defense = 0, int STR_mod = 0, int DEX_mod = 0, int INT_mod = 0);
};