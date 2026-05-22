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
	int SetExp(int exp) { this->exp = exp; return this->exp; }
	int GetExp(int exp) const { return this->exp; }
	int GetLevel() const { return level; }
    
 
private:
    int level;
    int exp;
    int maxExp;
    int gold;
};