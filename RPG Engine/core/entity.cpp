#include "entity.h"

Entity::Entity(int max_hp, int x, int y) {
	this->max_hp = max_hp;
	this->hp = max_hp;
	this->x = x;
	this->y = y;
}

void Entity::Heal(int amount) {
	hp = clamp(hp + amount, 0, max_hp);
}

void Entity::Damage(int amount) {
	hp = clamp(hp - amount, 0, max_hp);
}

void Entity::FullHeal() {
	hp = max_hp;
}

void Entity::Kill() {
	hp = 0;
}

void Entity::Move(int dx, int dy) {
	
}