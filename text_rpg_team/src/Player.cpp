#include "Player.h"
#include "LogManager.h"

#define YELLOW "\033[33m"
#define RESET "\033[0m"

using namespace std;

Player::Player(int level, int exp, int maxExp, int gold)
    : level(level),
    exp(exp),
    maxExp(maxExp),
    gold(gold),
    inventory()
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

void Player::Attack(Character* target) {
    target->TakeDamage(attackPower);
}

int Player::SetExp(int exp)
{
    this->exp = exp;
    if(exp>= maxExp)
    {
        this->LevelUp();
	}
    return this->exp;
}

void Player::LevelUp() {
	LogManager::GetInstance().Print(YELLOW "★ 레벨업! ★" RESET);
    this->level++;
    exp -= maxExp;
    
    this->maxHp += 20;
    this->attackPower += 5;
    this->hp = this->maxHp;
}

const vector<unique_ptr<Item>>& Player::GetInventory() const
{
    return inventory;
}

void Player::AddItem(unique_ptr<Item> item)
{
    if (item == nullptr)
    {
        return;
    }

    inventory.push_back(move(item));
}

void Player::RemoveItem(const string& itemName)
{
    for (auto iter = inventory.begin(); iter != inventory.end(); ++iter)
    {
        if ((*iter)->GetName() == itemName)
        {
            inventory.erase(iter);
            break;
        }
    }
}