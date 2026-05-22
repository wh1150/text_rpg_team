#pragma once
#include <string>

class Character {
public:
	virtual ~Character() {}

	int GetHp() const { return hp; }
	int GetMaxHp() const { return maxHp; }
	int GetAttackPower() const { return attackPower; }
	std::string GetName() const { return name; }

	void TakeDamage(int damage);
	virtual void Attack(Character* target) = 0;

protected:
	int hp;
	int maxHp;
	int attackPower;
	std::string name;
};