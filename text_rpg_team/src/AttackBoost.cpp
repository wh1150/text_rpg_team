#include "AttackBoost.h"
#include "Player.h"

AttackBoost::AttackBoost()
{
    this->name = "공격력 증가 포션";
    this->type = ItemType::AttackBoost;
    this->attackIncrease = 10;
}

void AttackBoost::UseItem(Player& player)
{
    const int attackPower = player.GetAttackPower() + attackIncrease;
    player.SetAttackPower(attackPower);
}
