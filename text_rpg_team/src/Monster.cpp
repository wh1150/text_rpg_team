#include "Monster.h"
#include <cstdlib>

void Monster::SetMonsterAbility(int playerLevel) {

	// 플레이어 레벨 * (hpScale ~ hpScale + 10 사이 랜덤 값)
	maxHp = playerLevel * ((rand() % 11) + hpScale);
	hp = maxHp;

	// 플레이어 레벨 * (attackPowerScale ~ attackPowerScale + 5 사이 랜덤 값)
	attackPower = playerLevel * ((rand() % 6) + attackPowerScale);
}

void Monster::Attack(Character* target) {
	target->TakeDamage(attackPower);
}