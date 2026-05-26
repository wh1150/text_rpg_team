#pragma once

#include "Player.h"

class Shop 
{
public:
    void OpenShop(Player& player);
    bool BuyPotion(Player& player);      
    bool BuyAttackItem(Player& player);  
};