#include "HealthPotion.h"
#include "Player.h"

HealthPotion::HealthPotion()
{
    this->name = "체력 포션";
    this->type = ItemType::HealthPotion;
    this->healthRestore = 50;
}

void HealthPotion::UseItem(Player& player)
{
    int health = player.GetHp() + healthRestore;
    health = std::min(health, player.GetMaxHp());
    player.SetHP(health);
}
