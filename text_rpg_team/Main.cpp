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
	srand((unsigned int)time(nullptr)); // 랜덤값 초기화

	string playerName = log.PrintTitle();

	
	Player player(1, 0, 100, 0);
	player.SetName(playerName);

	//TODO: 초기 아이템 설정 (테스트용) 추후 기본 소지 아이템을 설정할 때 변경이 필요합니다.
	//TODO: 아이템 클래스를 상속받은 자식 클래스들의 구현이 완료되어야 합니다.
	player.AddItem(make_unique<HealthPotion>());
	player.AddItem(make_unique<HealthPotion>());
	player.AddItem(make_unique<AttackBoost>());


	Monster* monster = CreateRandomMonster(player.GetLevel());
	/*
	* 로그 출력 가이드:
	* log.Print(Message) : 단순 메시지 출력. 가장 아래쪽 로그창에 출력됩니다.
	* log.PrintChoice(Message) : 선택지 메시지 출력. 메뉴창에 출력됩니다.
	*/
	

	// 전투 시작
	// log.PrintStatus(player);
	log.PrintStartBattle(player, *monster);
	log.PrintMenu("1. 공격  2. 상점  3. 도망 ");
	log.PrintInventory(player.GetInventory());


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
			log.Print("상점입니다.");
		}
		else if (input == '3')
		{
			log.Print("도망쳤습니다! 용사는 나약합니다.");
			break;
		}
		else
		{
			log.Print("잘못된 입력입니다. 다시 선택해주세요.");
		}
	}
	delete monster;
    return 0;
}
