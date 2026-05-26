// LogManager.cpp

#include <iostream>
#include <Windows.h>
#include "LogManager.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"
#include "UI.h"



void LogManager::Print(std::string message)
{
	Gotoxy(63, 26);
	cout << "                                      "; // 이전 로그 지우기
	Gotoxy(63, 26);
	cout << ">> " << message;
}

void LogManager::PrintChoice(std::string message)
{
	DrawChoice(message); // std::cout 대신 DrawLog() 사용.
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
	DrawLog(attacker.GetName() + " attacked " + defender.GetName() + "!");

	if(playerPtr != nullptr && monsterPtr != nullptr)
	{
		DrawStatus(*playerPtr, *monsterPtr);
	}
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
	DrawLog("★ Victory! Monster Defeated! ★");
	Sleep(500);

	DrawLog("Gained " + to_string(gold) + "Gold. (Total: " + to_string(player.GetGold()) + ")");
	Sleep(500);

	if(itemName != "")
	{
		DrawLog("Luck! You found an item: [" + itemName + "]!");
	}
	else
	{
		DrawLog("No items found this time.");
	}
}

//TODO: 하단의 함수들은 모두 출력 형식 변경 필요.PrintUseItem, PrintGetItem...


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