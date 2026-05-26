// LogManager.cpp

#include <iostream>
#include <Windows.h>
#include <string>
#include "LogManager.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"
#include "UI.h"

LogManager* LogManager::instance = nullptr;

void LogManager::Print(std::string message)
{
	Sleep(1000);
	Gotoxy(63, 26);
	cout << "											      "; // 이전 로그 지우기
	Gotoxy(63, 26);
	cout << ">> " << message;
}

void LogManager::PrintChoice(std::string message)
{
	DrawChoice(message); // std::cout 대신 DrawLog() 사용.
}

void LogManager::PrintMenu(std::string message)
{
	DrawMenu(message); // std::cout 대신 DrawMenu() 사용.
}

string LogManager::PrintTitle()
{
	DrawTitle(); // 게임 타이틀 출력

	int boxY = 20;
	Gotoxy(12, boxY + 1);
	cout << "용사의 이름을 입력하시오: ";

	string playerName;
	cin >> playerName;

	return playerName; // 이름 반환
}

void LogManager::PrintStartBattle(Player& player, Monster& monster)
{
	playerPtr = &player; // 플레이어 정보 저장 (HP 갱신을 위해)
	monsterPtr = &monster; // 몬스터 정보 저장 (HP 갱신을 위해)

	DrawLayout(); // 전투 레이아웃 초기화
	DrawBattleScene(player, monster); // 전투 장면 초기화
	DrawLog(monster.GetName() + " appeared!"); // 몬스터 등장 메시지

	DrawStatus(player, monster);


}


void LogManager::PrintAttack(Character& attacker, Character& defender)
{
	DrawLog(attacker.GetName() + "이/가 " + defender.GetName() + "을/를 공격!");

	if(playerPtr != nullptr && monsterPtr != nullptr)
	{
		DrawStatus(*playerPtr, *monsterPtr);
	}

	Sleep(1000); // 1초 대기. 전투가 눈에 보이도록 속도 조절.
}
/*
void LogManager::PrintStatus(Player& player)
{
	playerPtr = &player;
	DrawStatus(player, monsterPtr);
}
*/

void LogManager::PrintReward(Player& player, Monster& monster, int gold, std::string itemName)
{
	DrawLog("★ Victory! Monster Defeated! ★			");
	Sleep(1000);

	DrawLog("Gained " + to_string(gold) + "Gold. (Total: " + to_string(player.GetGold()) + ")");
	Sleep(1000);

	DrawLog("경험치 50획득! 현재: " +to_string(player.GetExp()));
	Sleep(1000);

	if(itemName != "")
	{
		DrawLog("Luck! You found an item: [" + itemName + "]!");
	}
	else
	{
		DrawLog("No items found this time.");
	}
	DrawStatus(player, monster);
}


void LogManager::PrintInventory(const std::map<std::string, int>& items)
{
	//TODO
}



//TODO: 하단의 함수들은 모두 출력 형식 변경 필요.PrintUseItem, PrintGetItem...


void LogManager::PrintUseItem(Item& item)
{
	std::string msg = "아이템 사용: [" + item.GetName() + "]";
	DrawLog(msg);
	DrawStatus(*playerPtr, *monsterPtr);
	Sleep(1000);
}

void LogManager::PrintGetItem(Item& item)
{
	std::string msg = "아이템 획득: [" + item.GetName() + "]";
	DrawLog(msg);
}


void LogManager::AddKill(Monster& monster)
{
	killCount[monster.GetName()]++;
}


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