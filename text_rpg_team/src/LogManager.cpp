// LogManager.cpp

#include <iostream>
#include "LogManager.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"


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
		<< std::endl;
}

void LogManager::PrintPlayerAttack(Player& player, Monster& monster)
{
	std::cout << player.GetName()
		<< " attacks "
		<< monster.GetName()
		<< "! "
		<< monster.GetName()
		<< " HP: "
		<< monster.GetHp()
		<< std::endl;
}

void LogManager::PrintMonsterAttack(Player& player, Monster& monster)
{
	std::cout << monster.GetName()
		<< " attacks "
		<< player.GetName()
		<< "! "
		<< player.GetName()
		<< " HP: "
		<< player.GetHp()
		<< std::endl;
}

void LogManager::PrintStatus(Player& player)
{
	std::cout << "[PLAYER]"
		<< " NAME: " << player.GetName()
		<< " LEVEL: " << player.GetLevel()
		<< " HP: " << player.GetMaxHp()
		<< " POWER: " << player.GetAttackPower()
		<< std::endl;
}

// TODO : Connect EXP / Gold reward values later
void LogManager::PrintReward(Player& player, Monster& monster)
{
	int exp = 0;
	int gold = monster.GetDropGold();

	std::cout << player.GetName() << " gained "
		<< exp << " EXP and "
		<< gold << " Gold. "
		<< "Current EXP: " << player.GetExp()
		<< ", Gold: " << player.GetGold()
		<< std::endl;
}

//TODO
void LogManager::PrintUseItem(Item& item)
{
	/**
	* TODO:
	* PrintItem LogMessage
	*/
}

//TODO
void LogManager::PrintGetItem(Item& item)
{
	/**
	* TODO:
	* PrintGetItem LogMessage
	*/
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
			<< std::endl;
	}
	std::cout << "==============================\n";
}