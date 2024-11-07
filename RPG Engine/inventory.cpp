#include "inventory.h"

Inventory::Inventory(unsigned int max_capacity) {
	this->max_capacity = max_capacity;
	this->cur_capacity = 0;

	slots.resize(max_capacity);
}

void Inventory::debug_print() {
	for (int i = 0; i < slots.size(); i++) {
		std::cout << "slot[" + std::to_string(i) + "] contains " << slots[i].amount << " [" + slots[i].item.getName() + "] with ID=" << slots[i].item.getID() << std::endl;
	}
}

void Inventory::debug_print_at(int i) {
	std::cout << "slot[" + std::to_string(i) + "] contains " << slots[i].amount << " [" + slots[i].item.getName() + "] with ID=" << slots[i].item.getID() << std::endl;

	ItemData itemData = slots[i].item.getData();

	switch (itemData.type) {
	case ItemType::WEAPON :
		Weapon* weapon;
		weapon = static_cast<Weapon*>(itemData.data);
		std::cout << "-+*ADDITIONAL ITEM DATA*+-" << std::endl;
		std::cout << " -damage=" << weapon->damage << std::endl;
		std::cout << " -additional strength=" << weapon->stats.STR << std::endl;
		std::cout << " -additional dexterity=" << weapon->stats.DEX << std::endl;
		std::cout << " -additional intelligence=" << weapon->stats.INT << std::endl;
		std::cout << "-+*ADDITIONAL ITEM DATA*+-" << std::endl;
	break;
	case ItemType::ARMOR :
		Armor* armor;
		armor = static_cast<Armor*>(itemData.data);
		std::cout << "-+*ADDITIONAL ITEM DATA*+-" << std::endl;
		std::cout << " -defense=" << armor->defense << std::endl;
		std::cout << " -additional strength=" << armor->stats.STR << std::endl;
		std::cout << " -additional dexterity=" << armor->stats.DEX << std::endl;
		std::cout << " -additional intelligence=" << armor->stats.INT << std::endl;
		std::cout << "-+*ADDITIONAL ITEM DATA*+-" << std::endl;
	break;
	}
}

bool Inventory::hasCapacity() {
	return cur_capacity < max_capacity;
}

int Inventory::getItemIndex(int id, bool check_for_available_space_only) {
	for (int i = 0; i < slots.size(); i++) {
		if (slots[i].item.getID() == id) {
			if (check_for_available_space_only) {
				if (slots[i].amount < MAX_SLOT_AMOUNT) {
					return i;
				}
				continue;
			}
			return i;
		}
	}

	return -1;
}

Item Inventory::getItem(int id) {
	int i = getItemIndex(id);
	return slots[i].item;
}

bool Inventory::addItem(Item item, unsigned int amount) {
	int remainder = amount;
	int index = getItemIndex(item.getID(), true);

	if (!item.isStackable()) {
		while (remainder > 0) {
			index = getItemIndex(EMPTY_ITEM); //get an empty slot

			if (index == -1) { return false; }

			slots[index].item = item;
			slots[index].amount = 1;

			remainder--;
			cur_capacity++;
		}
		return true;
	}

	//if it gets to this part of the code, the item must be stackable

	if (index != -1) { //check if there is an existing stack with available space only and, if there is, add the correct amount to the stack
		remainder = MAX_SLOT_AMOUNT - (slots[index].amount + amount); //ex: 99 - 95 + 3 = 1;
		slots[index].amount = clamp(slots[index].amount + amount, 0, MAX_SLOT_AMOUNT);

		if (remainder <= 0) {
			return true;
		}
	}
	
	if (hasCapacity()) {
		index = getItemIndex(EMPTY_ITEM); //get an empty slot

		if (index == -1) { return false; }

		slots[index].item = item;
		slots[index].amount = remainder;

		cur_capacity++;
	}

	return false;
}