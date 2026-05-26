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

private:
    bool isAttackItemUsed;
};