#pragma once
#include <string>
#include <vector>

class Player;
class LogManager;

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

//Player temp_player(1, 0, 100, 0);
//temp_player.AddItem(make_unique<HealthPotion>());
//Item::Use(temp_player, ItemType::HealthPotion);
//Item::UseRandom(temp_player);