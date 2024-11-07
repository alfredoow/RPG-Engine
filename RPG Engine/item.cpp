#include "item.h"

static unsigned int ID_POOL = 0;

Item::Item() {
	this->id = 0;
	this->name = "empty";
	this->stackable = false;
}

Item::Item(std::string name, bool stackable) {
	this->id = ++ID_POOL;
	this->name = name;
	this->stackable = stackable;
}

ItemData Item::getData() { return data; }

unsigned int Item::getID() { return id; }
std::string Item::getName() { return name; }
bool Item::isStackable() { return stackable; }

Weapon::Weapon(std::string name, int damage, int STR_mod, int DEX_mod, int INT_mod) : Item(name, false) {
	this->damage = damage;
	this->stats = { STR_mod, DEX_mod, INT_mod };
	this->data = { ItemType::WEAPON, this };
}

Armor::Armor(std::string name, int defense, int STR_mod, int DEX_mod, int INT_mod) : Item(name, false) {
	this->slot = ArmorSlot::HEAD;
	this->defense = defense;
	this->stats = { STR_mod, DEX_mod, INT_mod };
	this->data = { ItemType::ARMOR, this };
}