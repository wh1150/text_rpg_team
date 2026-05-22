#include "Player.h"

using namespace std;

Player::Player(const std::string& name, int level, int exp, int maxExp)
    : level(level),
    exp(exp),
    maxExp(maxExp)
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

int Player::GetExp(int exp) const
{
    return this->exp;
}

int Player::GetLevel() const
{
    return this->level;
}

int Player::GetGold() const
{
    return this->gold;
}

int Player::SetGold(int gold)
{
    this->gold = gold;
    return this->gold;
}