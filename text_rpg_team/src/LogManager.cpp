// LogManager.cpp

#include <iostream>
#include "../include/LogManager.h"
#include "../Player.h"
#include "../Monster.h"
#include "../include/Item.h"
#include "../Character.h"


void LogManager::Print(std::string message)
{
	std::cout << message << std::endl;
}

void LogManager::PrintStartBattle(Monster& monster)
{
	std::cout << "Monster " << monster.GetName()
		<< " appeared! HP: "
		<< monster.GetMaxHp()
		<< " ATK: "
		<< monster.GetAttackPower()
		<< "\n";
}


void LogManager::PrintAttack(Character& attacker, Character& defender)
{
	std::cout << attacker.GetName()
		<< " attacks "
		<< defender.GetName()
		<< "! "
		<< defender.GetName()
		<< " HP: "
		<< defender.GetHp()
		<< "\n";
}

void LogManager::PrintStatus(Player& player)
{
	std::cout << "[PLAYER]"
		<< " NAME: " << player.GetName()
		<< " LEVEL: " << player.GetLevel()
		<< " HP: " << player.GetMaxHp()
		<< " POWER: " << player.GetAttackPower()
		<< "\n";
}


void LogManager::PrintReward(Player& player, Monster& monster)
{
	int exp = 0; //TODO: Calculate EXP based on monster's level and player's level
	int gold = monster.GetDropGold();
	std::cout << player.GetName() << " gained "
		<< exp << " EXP and "
		<< gold << " Gold. "
		<< "Current EXP: " << player.GetExp()
		<< ", Gold: " << player.GetGold()
		<< "\n";
}

void LogManager::PrintUseItem(Item& item)
{
	std::cout << "You used an item: "
		<< item.GetName() << "!\n";
}

void LogManager::PrintGetItem(Item& item)
{
	std::cout << "You obtained an item: "
		<< item.GetName() << "!\n";
}

//TODO
void LogManager::AddKill(Monster& monster)
{
	killCount[monster.GetName()]++;
}

// TODO
void LogManager::ShowKillCount()
{
	std::cout << "\n===== Monster Kill Count =====\n";
	for (const auto& monster : killCount)
	{
		std::cout << monster.first
			<< " : "
			<< monster.second
			<< "\n";
	}
	std::cout << "==============================\n";
}