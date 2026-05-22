#include "ShadowCatMonster.h"

ShadowCatMonster::ShadowCatMonster(int playerLevel) {
	hpScale = 20;
	attackPowerScale = 30;
	SetMonsterAbility(playerLevel);

	name = "Shadow Cat";
	dropGold = (rand() % 21) + 15; // 15 ~ 35
}