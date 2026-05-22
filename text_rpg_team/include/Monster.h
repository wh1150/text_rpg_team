#pragma once
#include "Character.h"

class Monster : public Character {
public:

	int GetDropGold() const { return dropGold; }
	void Attack(Character* target) override;

protected:

	Monster() : dropGold(0), hpScale(0), attackPowerScale(0) {}
	void SetMonsterAbility(int playerLevel);

	int dropGold;
	int hpScale;
	int attackPowerScale;
};