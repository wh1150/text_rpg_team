#pragma once
#include "Item.h"

class AttackBoost : public Item
{
private:
    int attackIncrease;

public:
    std::string GetName() override;
    void Use(Player& player) override;
};
