// LogManager.h

#pragma once
#include <string>
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
	std::map<std::string, int> killCount;
public:
	// 단순 메시지를 출력합니다.
	void Print(std::string message);

	// 전투 시작 시 몬스터 정보를 출력합니다.
	void PrintStartBattle(Monster& monster);

	// 공격로그: PrintAttack(공격자, 방어자) 순서로 넣어주세요.
	// Player, Monster 모두 Character를 상속받으므로 그대로 넣으면 됩니다.
	void PrintAttack(Character& attacker, Character& defender);

	// 현재 플레이어의 능력치를 출력합니다.
	void PrintStatus(Player& player);

	// 전투 승리 보상을 출력합니다. (EXP 50 고정 출력)
	// 중요: 전투 시스템에서 플레이어의 EXP를 먼저 올린 후 호출해주세요.
	void PrintReward(Player& player, Monster& monster);

	// 아이템 사용/획득 로그를 출력합니다.
	void PrintUseItem(Item& item);
	void PrintGetItem(Item& item);

	// 몬스터 처치 기록 및 확인
	void AddKill(Monster& monster);
	void ShowKillCount();
};