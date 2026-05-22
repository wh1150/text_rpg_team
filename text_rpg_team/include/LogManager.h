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

	// TODO : Print reward message
	void PrintReward(Player& player, Monster& monster);

	//: Print item usage message
	void PrintUseItem(Item& item);

	// Print item message
	void PrintGetItem(Item& item);

	// TODO : Add monster kill count
	void AddKill(Monster& monster);

	// TODO : Show monster kill count
	void ShowKillCount();
};