#include "Player.h"

using namespace std;

Player::Player(int level, int exp, int maxExp, int gold)
    : level(level),
    exp(exp),
    maxExp(maxExp),
    gold(gold)
{
    this->name = name;
    this->hp = 200;
    this->maxHp = 200;
    this->attackPower = 30;
}

int Player::SetHP(int hp)
{
    this->hp = hp;
    return this->hp;
}

int Player::SetMaxHP(int maxHp)
{
    this->maxHp = maxHp;
    return this->maxHp;
}

int Player::SetAttackPower(int attackPower)
{
    this->attackPower = attackPower;
    return this->attackPower;
}

int Player::SetExp(int exp)
{
    this->exp = exp;
    if(exp>= maxExp)
    {
        level++;
        exp -= maxExp;
	}
    return this->exp;
}