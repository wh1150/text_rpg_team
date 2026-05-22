#pragma once

#include <string>
#include "Character.h"

using namespace std; 

class Player : public Character
{
public:
    Player(const string& name, int level, int exp, int maxExp);
	int SetHP(int hp);
	int SetMaxHP(int maxHp);
	int SetAttackPower(int attackPower);
    
 
private:
    int level;
    int exp;
    int maxExp;
};