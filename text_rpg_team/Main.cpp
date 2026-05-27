#include <iostream>
#include <conio.h>
#include <windows.h>
#include <map>
#include <string>
#include <ctime>
#include "LogManager.h"
#include "Player.h"
#include "HellRabbitMonster.h"
#include "CrazyChihuahuaMonster.h"
#include "ShadowCatMonster.h"
#include "Battle.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include "Shop.h"


Monster* CreateRandomMonster(int playerLevel)
{
	int random = rand() % 3;

	switch (random)
	{
	case 0:
		return new HellRabbitMonster(playerLevel);

	case 1:
		return new CrazyChihuahuaMonster(playerLevel);

	case 2:
		return new ShadowCatMonster(playerLevel);
	}

	return nullptr;
}

void HideCursor()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(consoleHandle, &cursorInfo);

	cursorInfo.bVisible = false; // 커서 숨기기

	SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

using namespace std;
int main() 
{
	HideCursor();
	LogManager log;
	Battle battle;
	Shop shop;
	srand((unsigned int)time(nullptr)); // 랜덤값 초기화

	string playerName = log.PrintTitle();

	bool isGameOver = false;

	Player player(1, 0, 100, 0);
	player.SetName(playerName);

	//TODO: 초기 아이템 설정 (테스트용) 추후 기본 소지 아이템을 설정할 때 변경이 필요합니다.
	//TODO: 아이템 클래스를 상속받은 자식 클래스들의 구현이 완료되어야 합니다.
	player.AddItem(make_unique<HealthPotion>());
	player.AddItem(make_unique<HealthPotion>());
	player.AddItem(make_unique<AttackBoost>());
	system("cls"); // 화면 초기화
	while (!isGameOver)
	{
		while (_kbhit())
		{
			_getch();
		}	

		Monster* monster = CreateRandomMonster(player.GetLevel());

		// 전투 시작
		log.PrintStartBattle(player, *monster);
		log.Print(monster->GetName() + "이(가) 나타났다!");
		//log.PrintMenu("1. 공격  2. 상점  3. 도망 ");
		log.PrintInventory(player.GetInventory());
		log.PrintShop();

		
		// 전투 루프 (선택지 입력 대기)
		while (monster->GetHp() > 0)
		{
			char input = 0;

			while (input == 0)
			{
				log.PrintMenu("1. 공격  2. 상점  3. 도망 ");
				log.PrintChoice("어떻게 할까? ");

				log.PrintStartBattle(player, *monster); // 몬스터 애니메이션 갱신
				Sleep(100);

				if (_kbhit())
				{
					input = _getch();
				}
			}

			if (input == '1')
			{
				LogManager::GetInstance().PlaySelectSound();
				battle.StartBattle(player, *monster);
				if(player.GetHp() <= 0)
				{
					isGameOver = true;
					break;
				}
			}
			else if (input == '2')
			{
				LogManager::GetInstance().PlaySelectSound();
				log.Print("상점에 입장했습니다.");
				shop.OpenShop(player);
			}
			else if (input == '3')	
			{
				LogManager::GetInstance().PlaySelectSound();
				log.Print("도망쳤습니다! 용사는 나약합니다.");
				isGameOver = true;
				break;
			}
			else
			{
				LogManager::GetInstance().PlayFalseSound();
				log.Print("잘못된 입력입니다. 다시 선택해주세요.");
			}
		}
		if (monster->GetHp() <= 0)
		{
			log.Print("다음 몬스터가 등장합니다.");
		}
		delete monster;
		monster = nullptr;
	}
    return 0;
}
