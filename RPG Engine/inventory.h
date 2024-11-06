#pragma once

#include "Item.h"
#include "JMath.h"
#include <iostream>
#include <vector>

constexpr unsigned int MAX_SLOT_AMOUNT = 99;

struct Slot {
public:
	Item item;
	unsigned int amount = 0;
};

class Inventory {
private:
	unsigned int max_capacity;
	unsigned int cur_capacity;
	std::vector<Slot> slots;
public:
	Inventory(unsigned int max_capacity);

	void debug_print();
	void debug_print_at(int i);

	bool hasCapacity();

	int getItemIndex(int id, bool check_for_available_space_only = false);

	Item getItem(int id);
	bool addItem(Item item, unsigned int amount);
};