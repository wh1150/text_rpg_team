#include <iostream>
#include <conio.h>
#include <windows.h>
#include <map>
#include <string>
#include "LogManager.h"
#include "Player.h"
#include "HellRabbitMonster.h"
#include "Battle.h"

using namespace std;
int main() 
{

	LogManager log;
	Battle battle;

	string playerName = log.PrintTitle();

	
	Player player(1, 0, 100, 0);
	player.SetName(playerName);
	HellRabbitMonster monster(player.GetLevel()); // TODO: 임시로 처음 등장 시켜놓은 몬스터입니다. 추후 변경이 필요합니다.
	// std::map<std::string, int> inventory = { {"체력 포션", 3}, {"힘 포션", 3} };
	/*
	* 로그 출력 가이드:
	* log.Print(Message) : 단순 메시지 출력. 가장 아래쪽 로그창에 출력됩니다.
	* log.PrintChoice(Message) : 선택지 메시지 출력. 메뉴창에 출력됩니다.
	*/
	

	// 전투 시작
	// log.PrintStatus(player);
	log.PrintStartBattle(player, monster);
	log.PrintMenu("1. 공격  2. 상점  3. 도망 ");
	// log.PrintInventory(inventory);// 인벤토리 출력입니다. 임시로 출력해놓은 포션을 볼 수 있습니다. 변경 시 이 부분도 변경해야합니다.


	// 전투 루프 (선택지 입력 대기)
	while (monster.GetHp() > 0)
	{
		log.PrintChoice("어떻게 할까? ");

		// 사용자 입력 대기
		char input = _getch();

		if (input == '1')
		{
			battle.StartBattle(player, monster);
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
    return 0;
}
