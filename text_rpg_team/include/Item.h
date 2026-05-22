#pragma once
#include <string>

class Player;

class Item
{
protected:
    std::string name;

public:
    virtual std::string GetName();
    virtual void Use(Player& player) = 0;
};
