#pragma once

#include <string>
#include "Character.h"
#include <map>

using namespace std; 

class Player : public Character
{
public:
    Player(int level, int exp, int maxExp, int gold);
    int SetHP(int hp);
    int SetMaxHP(int maxHp);
    int SetAttackPower(int attackPower);
    int GetGold() const { return gold; }
    int SetGold(int gold) { this->gold = gold; return this->gold; }
    int SetExp(int exp);
    int GetExp() const { return this->exp; }
    int GetLevel() const { return level; }
    string GetName() const { return name; }
    string SetName(const string& name) { this->name = name; return this->name; }    
    void SetInventory(const map<string, int>& inventory);
    void Attack(Character* target) override;
    const map<string, int>& GetInventory() const;

private:
    int level;
    int exp;
    int maxExp;
    int gold;
    map<string, int> inventory;
	void LevelUp();
};