#pragma once

#include "Player.h"

class Shop
{
public:
    void OpenShop(Player& player);

private:
    void BuyPotion(Player& player);
    void BuyAttackItem(Player& player);
};