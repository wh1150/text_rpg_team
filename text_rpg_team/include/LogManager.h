// LogManager.h

#pragma once
#include <string>
#include <map>

class Character;
class Player;
class Monster;
class Item;

class LogManager
{
private:
	std::map<std::string, int> killCount;
public:
	// General Print Message
	void Print(std::string message);

	// Start Battle Message
	void PrintStartBattle(Monster& monster);

	// Attack! arracker -> defender
	void PrintAttack(Character& attacker, Character& defender);

	// Print PlayerStatus Message
	void PrintStatus(Player& player);

	// Print reward message TODO: Calculate EXP based on monster's level and player's level
	void PrintReward(Player& player, Monster& monster);

	// Print item usage message
	void PrintUseItem(Item& item);

	// Print item message
	void PrintGetItem(Item& item);

	// Add monster kill count
	void AddKill(Monster& monster);

	// Show monster kill count
	void ShowKillCount();
};