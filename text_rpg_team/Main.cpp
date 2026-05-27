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


using namespace std;
int main() 
{

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

	while (!isGameOver)
	{
		while (_kbhit())
		{
			_getch();
		}

		Monster* monster = CreateRandomMonster(player.GetLevel());

		// 전투 시작
		log.PrintStartBattle(player, *monster);
		log.PrintMenu("1. 공격  2. 상점  3. 도망 ");
		log.PrintInventory(player.GetInventory());
		log.PrintShop();

		
		// 전투 루프 (선택지 입력 대기)
		while (monster->GetHp() > 0)
		{
			log.PrintChoice("어떻게 할까? ");

			// 사용자 입력 대기
			char input = _getch();

			if (input == '1')
			{
				battle.StartBattle(player, *monster);
			}
			else if (input == '2')
			{
				log.Print("상점에 입장했습니다.");
				shop.OpenShop(player);
			}
			else if (input == '3')
			{
				log.Print("도망쳤습니다! 용사는 나약합니다.");
				isGameOver = true;
				break;
			}
			else
			{
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
