#include <iostream>

#include "inventory.h"

Inventory inventory = Inventory(10);

Weapon iron_sword = Weapon("iron sword", 15);
Armor quartz_ring = Armor("quartz ring", 0, 6, 3, 0);

int main() {
	
	inventory.addItem(iron_sword, 2);
	inventory.addItem(quartz_ring, 5);

	inventory.debug_print_at(0);
	inventory.debug_print_at(3);

	return 0;
}