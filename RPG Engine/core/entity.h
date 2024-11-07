#pragma once

#include "JMath.h"

class Entity {
protected:
	int max_hp = 1;
	int hp = max_hp;
public:
	int x = 0;
	int y = 0;

	Entity(int max_hp, int x = 0, int y = 0);

	void Heal(int amount);
	void Damage(int amount);

	void FullHeal();
	void Kill();

	void Move(int dx, int dy);
};