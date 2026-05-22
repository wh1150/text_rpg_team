// Battle.cpp
#include <cstdlib>
#include "Battle.h"

void Battle(Character& player, Monster& monster)
{
    cout << "======================" << endl;
    cout << monster.name << " 등장!" << endl;
    cout << "몬스터 HP : " << monster.hp << endl;
    cout << "======================" << endl;

    while (player.hp > 0 && monster.hp > 0)
    {
        cout << "[플레이어 공격!]" << endl;

        monster.hp -= player.attack;

        if (monster.hp < 0)
        {
            monster.hp = 0;
        }

        cout << monster.name << " HP : " << monster.hp << endl;

        if (monster.hp <= 0)
        {
            cout << monster.name << " 처치 성공!" << endl;

            break;
        }

        cout << "[몬스터 공격!]" << endl;

        player.hp -= monster.attack;

        if (player.hp < 0)
        {
            player.hp = 0;
        }

        cout << "플레이어 HP : " << player.hp << endl;

    }

    if (player.hp > 0)
    {
        cout << "전투 승리!" << endl;

        player.exp += 50;

        cout << "경험치 +50" << endl;

        int rewardGold = 10 + rand() % 11;

        player.gold += rewardGold;

        cout << "골드 +" << rewardGold << endl;

        int dropChance = rand() % 100;

        if (dropChance < 30)
        {
            cout << "아이템 획득!" << endl;
        }
        else
        {
            cout << "아이템 없음!" << endl;
        }

        if (player.exp >= 100)
        {
            player.level++;

            player.exp -= 100;

            cout << "레벨 업!" << endl;
            cout << "현재 레벨 : " << player.level << endl;
        }
    }
    else
    {
        cout << "플레이어 패배..." << endl;
    }
}