// LogManager.cpp

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <map>
#include "LogManager.h"
#include "Player.h"
#include "Monster.h"
#include "Item.h"
#include "UI.h"

LogManager* LogManager::instance = nullptr;

void LogManager::Print(std::string message)
{
	DrawLog(message);
	Sleep(1000);
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
	DrawTitle();

	int boxY = 20;

	string enterName = "용사의 이름을 입력하시오: ";
	string nameLimit = "영문/숫자 입력은 최대 10자, 한글입력은 최대 6자 입니다.";
	string playerName;

	Gotoxy(12, boxY + 3);
	cout << nameLimit;

	Gotoxy(12, boxY + 1);
	cout << enterName;

	while (true)
	{
		char ch = _getch();


		// 공백은 입력받지 않음
		if (ch == ' ')
		{
			// 공백 입력 시 무시
			continue;
		}

		// 엔터
		else if (ch == '\r')
		{
			if (!playerName.empty())
				break;
		}

		// 백스페이스
		else if (ch == '\b')
		{
			if (!playerName.empty())
			{
				playerName.pop_back();
				cout << "\b \b";
			}
		}
		// 최대 글자 수 제한 (영어기준 10자. 한글기준 6자 가능)
		else if (playerName.size() < 10)
		{
			playerName += ch;
			cout << ch;
		}
	}
	return playerName;
}

void LogManager::PrintStartBattle(Player& player, Monster& monster)
{
	playerPtr = &player; // 플레이어 정보 저장 (HP 갱신을 위해)
	monsterPtr = &monster; // 몬스터 정보 저장 (HP 갱신을 위해)

	DrawLayout(); // 전투 레이아웃 초기화
	DrawBattleScene(player, monster); // 전투 장면 초기화
	DrawLog(monster.GetName() + " 등장!"); // 몬스터 등장 메시지

	DrawStatus(player, monster);

	PrintInventory(player.GetInventory());


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
	DrawLog("★ 축! 몬스터를 해치웠다!! ★");
	Sleep(1000);

	DrawLog("골드 " + to_string(gold) + "획득. (총: " + to_string(player.GetGold()) + ")");
	Sleep(1000);

	DrawLog("경험치 50획득! 현재: " +to_string(player.GetExp()));
	Sleep(1000);

	if(itemName != "")
	{
		DrawLog("아이템 발견: [" + itemName + "]!");
		Sleep(1000);
	}
	else
	{
		DrawLog("이번엔 아이템이 안나왔네요..");
		Sleep(1000);
	}
	DrawStatus(player, monster);
}


void LogManager::PrintInventory(const std::vector<std::unique_ptr<Item>>& inventory)
{
	// 아이템 이름과 개수를 세기 위한 맵
	// 아이템 이름을 키로, 개수를 값으로 저장합니다.
	std::map<std::string, int> itemCount;

	// 인벤토리를 순회하면서 아이템 이름과 개수를 세고 맵에 저장합니다.
	for (const auto& item : inventory)
	{
		if (item != nullptr)
		{
			itemCount[item->GetName()]++;
		}
	}

	// 출력용 문자열 리스트
	std::vector<std::string> itemList;

	// 맵을 순회해서 아이템 정보 확인합니다.
	for (const auto& pair : itemCount)
	{
		// pair.first는 아이템 이름, pair.second는 개수입니다.
		itemList.push_back(pair.first + " x" + std::to_string(pair.second));
	}

	// 화면에 출력합니다.
	DrawInventory(itemList);
}


void LogManager::PrintUseItem(Item& item)
{
	std::string msg = "아이템 사용: [" + item.GetName() + "]";
	DrawLog(msg);

	if (playerPtr != nullptr)
	{
		DrawStatus(*playerPtr, *monsterPtr);
	}
	Sleep(1000);
}

void LogManager::PrintGetItem(Item& item)
{
	std::string msg = "아이템 획득: [" + item.GetName() + "]";
	DrawLog(msg);

	if(playerPtr != nullptr)
	{
		PrintInventory(playerPtr->GetInventory());
	}
	Sleep(1000);
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


void LogManager::PrintShop()
{
	DrawShop();
}


void LogManager::PrintStatus()
{
	if(playerPtr != nullptr && monsterPtr != nullptr)
	{
		DrawStatus(*playerPtr, *monsterPtr);
	}
}