// LogManager.h

#pragma once
#include <string>
#include <vector>
#include <map>

class Character;
class Player;
class Monster;
class Item;



/**
* [LogManager 사용 가이드]
* 1. 게임 내 모든 출력(메시지, 전투 로그 등)을 담당합니다.
* 2. 전투 시스템 관리자는 공격 시 PrintAttack()을 호출해주세요.
* 3. 보상 처리 후 PrintReward()를 호출하면 결과가 출력됩니다.
*/



class LogManager
{
private:
	static LogManager* instance;

	std::map<std::string, int> killCount;

	std::map<std::string, int>* inventoryPtr = nullptr;

	Player* playerPtr = nullptr;

	Monster* monsterPtr = nullptr;
public:
	LogManager() { instance = this; }
	static LogManager& GetInstance() { return *instance; }



	// 단순 메시지를 출력합니다.
	void Print(std::string message);

	void PrintChoice(std::string message);

	void PrintMenu(std::string message);

	// 게임 타이틀을 출력하고 플레이어 이름을 입력받습니다.
	std::string PrintTitle();

	// 전투 시작 시 몬스터 정보를 출력합니다.
	void PrintStartBattle(Player& player, Monster& monster);

	// 공격로그: PrintAttack(공격자, 방어자) 순서로 넣어주세요.
	// Player, Monster 모두 Character를 상속받으므로 그대로 넣으면 됩니다.
	void PrintAttack(Character& attacker, Character& defender);

	/*
	* 현재 사용하지 않아 주석처리 해놓습니다.
	// 현재 플레이어의 능력치를 출력합니다.
	void PrintStatus(Player& player);
	*/

	// 전투 승리 보상을 출력합니다. (EXP 50 고정 출력)
	void PrintReward(Player& player, Monster& monster, int gold, std::string itemName="");


	void PrintInventory(const std::vector<std::unique_ptr<Item>>& inventory);

	// 인벤토리 연결 함수
	void SetInventory(std::map<std::string, int>& inventory) {
		inventoryPtr = &inventory;
	}

	// 아이템 사용/획득 로그를 출력합니다.
	void PrintUseItem(Item& item);
	void PrintGetItem(Item& item);

	// 몬스터 처치 기록 및 확인
	void AddKill(Monster& monster);
	void ShowKillCount();

	void PrintShop();
};