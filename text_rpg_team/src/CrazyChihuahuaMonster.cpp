#include "CrazyChihuahuaMonster.h"

CrazyChihuahuaMonster::CrazyChihuahuaMonster(int playerLevel) {
	hpScale = 50;
	attackPowerScale = 20;
	SetMonsterAbility(playerLevel);

	name = "Crazy Chihuahua";
	dropGold = (rand() % 41) + 10; // 10 ~ 50
}