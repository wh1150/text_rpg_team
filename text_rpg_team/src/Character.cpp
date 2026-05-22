#include "Character.h"

void Character::TakeDamage(int damage) {
	hp -= damage;
	if (hp < 0) hp = 0;
}