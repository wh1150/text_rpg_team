#pragma once
#include "Character.h"

class Monster : public Character {
public:
	Monster(int playerLevel);

	int GetDropGold() const { return dropGold; }

private:
	int dropGold;
	void SetMonsterAbility(int playerLevel);
};