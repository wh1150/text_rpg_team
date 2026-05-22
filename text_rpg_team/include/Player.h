#pragma once

#include <string>
#include "Character.h"

using namespace std; 

class Player : public Character
{
public:
    Player(const string& name, int level, int exp, int maxExp, int gold);
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
 
private:
    int level;
    int exp;
    int maxExp;
    int gold;
};