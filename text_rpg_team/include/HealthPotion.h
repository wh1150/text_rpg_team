#pragma once
#include "Item.h"

class HealthPotion : public Item
{
private:
    int healthRestore;

public:
    HealthPotion();
    void UseItem(Player& player) override;
};
