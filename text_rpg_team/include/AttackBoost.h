#pragma once
#include "Item.h"

class AttackBoost : public Item
{
private:
    int attackIncrease;

public:
    AttackBoost();
    void UseItem(Player& player) override;
};
