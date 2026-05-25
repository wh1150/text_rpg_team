#include <iostream>
#include <conio.h>
#include <windows.h>
#include "LogManager.h"
#include "Player.h"
#include "HellRabbitMonster.h"

using namespace std;
int main()
{

	LogManager log;

	string playerName = log.PrintTitle();

	
	Player player(1, 0, 100, 0);
	player.SetName(playerName);
	HellRabbitMonster monster(player.GetLevel()); // TODO: 임시로 처음 등장 시켜놓은 몬스터입니다. 추후 변경이 필요합니다.
	
	/*
	* 로그 출력 가이드:
	* log.Print(Message) : 단순 메시지 출력. 가장 아래쪽 로그창에 출력됩니다.
	* log.PrintChoice(Message) : 선택지 메시지 출력. 메뉴창에 출력됩니다. 아이템/상점 기능 추가시 변경하여 사용합니다.
	*/
	

	// 전투 시작
	// log.PrintStatus(player);
	log.PrintStartBattle(player, monster);
	

	// 전투 루프 (선택지 입력 대기)
	while (monster.GetHp() > 0)
	{
		log.PrintChoice("어떻게 할까? ");

		// 사용자 입력 대기
		char input = _getch();

		if (input == '1')
		{
			log.Print("공격을 선택했습니다!");
			/*
			* TODO:
			* 전투 루프 구현
			* 플레이어가 공격을 하면 몬스터도 플레이어를 공격하도록 구현해주세요.
			*/
		}
		else if (input == '2')
		{
			log.Print("아이템 기능은 아직 준비 중입니다.");
			/*
			* TODO:
			* 아이템 사용 기능을 구현해주세요.
			* 전투 중 아이템을 사용하도록 합니다.
			*/
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
