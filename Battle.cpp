// Battle.cpp
#include <cstdlib>
#include "Battle.h"

void Battle(Character& player, Monster& monster)
{
    cout << "======================\n";
    cout << monster.name << " 등장!\n";
    cout << "몬스터 HP : " << monster.hp << "\n";
    cout << "======================\n\n";

    // 턴제 전투
    while (player.hp > 0 && monster.hp > 0)
    {
        // ===== 플레이어 턴 =====
        cout << "[플레이어 공격!]\n";

        monster.hp -= player.attack;

        if (monster.hp < 0)
        {
            monster.hp = 0;
        }

        cout << monster.name << " HP : " << monster.hp << "\n";

        // 몬스터 사망 체크
        if (monster.hp <= 0)
        {
            cout << "\n" << monster.name << " 처치 성공!\n";
            break;
        }

        // ===== 몬스터 턴 =====
        cout << "[몬스터 공격!]\n";

        player.hp -= monster.attack;

        if (player.hp < 0)
        {
            player.hp = 0;
        }

        cout << "플레이어 HP : " << player.hp << "\n\n";
    }

    // ===== 전투 결과 =====
    if (player.hp > 0)
    {
        cout << "전투 승리!\n";

        // 경험치 획득
        player.exp += 50;

        cout << "경험치 +50\n";

        // 골드 랜덤 지급
        int rewardGold = 10 + rand() % 11;

        player.gold += rewardGold;

        cout << "골드 +" << rewardGold << "\n";

        // 아이템 드랍 30%
        int dropChance = rand() % 100;

        if (dropChance < 30)
        {
            cout << "아이템 획득!\n";
        }
        else
        {
            cout << "아이템 없음!\n";
        }

        // 레벨업
        if (player.exp >= 100)
        {
            player.level++;

            player.exp -= 100;

            cout << "레벨 업!\n";
            cout << "현재 레벨 : " << player.level << "\n";
        }
    }
    else
    {
        cout << "플레이어 패배...\n";
    }
}