#pragma once
#include <string>
#include <vector>

class Player;

enum class ItemType { None, HealthPotion, AttackBoost };

class Item
{
protected:
    std::string name;
    ItemType type;
    int price;

public:
    std::string GetName() const { return name; }
    ItemType GetType() const { return type; }
    int GetPrice() const { return price; }

    virtual void UseItem(Player& player) = 0;
    virtual ~Item() = default;

private:
    static ItemType GetRandomType(const std::vector<ItemType>& types);
    
public:
    static bool Use(Player& player, ItemType itemName);
    static bool UseRandom(Player& player);
};
