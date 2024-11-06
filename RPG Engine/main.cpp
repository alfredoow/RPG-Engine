#include <iostream>

#include "inventory.h"

Inventory inventory = Inventory(10);

Weapon iron_sword = Weapon("iron sword", 15);

int main() {
	inventory.addItem(iron_sword, 5);
	inventory.debug_print_at(0);

	return 0;
}