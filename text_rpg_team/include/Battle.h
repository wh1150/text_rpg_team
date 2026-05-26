#pragma once

#include "Player.h"
#include "Monster.h"

class Battle
{
public:
    Battle();

    void StartBattle(Player& player, Monster& monster);

private:
    void PlayerTurn(Player& player, Monster& monster, int& addedAttackPower);
    void MonsterTurn(Player& player, Monster& monster);

    void GiveReward(Player& player, Monster& monster);

    bool IsDead(Character* character);

    void UsePotion(Player& player); // TODO : 아이템 클래스에서 구현 예정
    void UseAttackItem(Player& player); // TODO : 아이템 클래스에서 구현 예정

private:
    bool isAttackItemUsed;
};