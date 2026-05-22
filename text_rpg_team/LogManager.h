// LogManager.h

#pragma once
#include <string>
#include <map>


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

	// Player -> Monster attack!
	void PrintPlayerAttack(Player& player, Monster& monster);

	// Monster -> Player attack!
	void PrintMonsterAttack(Player& player, Monster& monster);

	// Print PlayerStatus Message
	void PrintStatus(Player& player);

	// TODO : Print item message
	void PrintGetItem(Item& item);

	// TODO : Print reward message
	void PrintReward(Player& player, Monster& monster);
	/* if reward id in gamemanager */
	/* void PrintReward(Player& player, int exp, int gold); */

	// TODO : Print item usage message
	void PrintUseItem(Item& item);

	// TODO : Add monster kill count
	void AddKill(Monster& monster);

	// TODO : Show monster kill count
	void ShowKillCount();
};