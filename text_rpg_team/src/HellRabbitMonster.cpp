#include "HellRabbitMonster.h"

HellRabbitMonster::HellRabbitMonster(int playerLevel) {
	hpScale = 100;
	attackPowerScale = 10;
	SetMonsterAbility(playerLevel);

	name = "Hell Rabbit";
	dropGold = (rand() % 31) + 30; // 30 ~ 60
}