#pragma once
#include "Item.h"

class HealthPotion : public Item
{
private:
    int healthRestore;

public:
    std::string GetName() override;
    void Use(Player& player) override;
};
