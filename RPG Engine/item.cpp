#include "item.h"

static unsigned int ID_POOL = 0;

Item::Item() {
	this->id = 0;
	this->name = "empty";
}

Item::Item(std::string name) {
	this->id = ++ID_POOL;
	this->name = name;
}

ItemData Item::getData() { return data; }

unsigned int Item::getID() { return id; }
std::string Item::getName() { return name; }

Weapon::Weapon(std::string name, int damage, int STR_mod, int DEX_mod, int INT_mod) : Item(name) {
	this->damage = damage;
	this->stats = { STR_mod, DEX_mod, INT_mod };
	this->data = { WEAPON, this };
}