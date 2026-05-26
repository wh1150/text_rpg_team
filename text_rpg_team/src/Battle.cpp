#include "Battle.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

Battle::Battle()
    : isAttackItemUsed(false)
{
}

void Battle::StartBattle(Player& player, Monster& monster)
{
    // 전투 시작 시 아이템 사용 여부 초기화
    isAttackItemUsed = false;

    cout << "===== 전투 시작 =====\n";
    cout << monster.GetName() << " 등장!\n";

    while (!IsDead(&player) && !IsDead(&monster))
    {
        PlayerTurn(player, monster);

        if (!IsDead(&monster))
        {
            MonsterTurn(player, monster);
        }
    }

    if (!IsDead(&player))
    {
        cout << "전투 승리!\n";

        GiveReward(player, monster);
    }
    else
    {
        cout << "플레이어 패배...\n";
    }
}

void Battle::PlayerTurn(Player& player, Monster& monster)
{
    cout << "[플레이어 턴]\n";

    // 체력 30% 이하일 때 포션 사용
    if (player.GetHp() <= player.GetMaxHp() * 0.3f)
    {
        UsePotion(player);
    }

    // 풀피 상태일 때 공격력 증가 아이템 사용 (1회만)
    if (player.GetHp() == player.GetMaxHp() && !isAttackItemUsed)
    {
        UseAttackItem(player);

        isAttackItemUsed = true;
    }

    player.Attack(&monster);

    cout << monster.GetName()
        << " HP : "
        << monster.GetHp()
        << "\n";
}

void Battle::MonsterTurn(Player& player, Monster& monster)
{
    cout << "[몬스터 턴]\n";

    monster.Attack(&player);

    cout << player.GetName()
        << " HP : "
        << player.GetHp()
        << "\n";
}

void Battle::GiveReward(Player& player, Monster& monster)
{
    // 경험치 획득
    int newExp = player.GetExp() + 50;

    player.SetExp(newExp);

    cout << "경험치 50 획득!\n";

    // 레벨업 // 전투시스템 체크리스트에 경험치 100이상 흭득 시 레벨업이 있어 만들어둠
    if (player.GetExp() >= 100)
    {
        cout << "레벨 업!\n";

        player.SetExp(0);
    }

    // 골드 획득
    int rewardGold = 10 + rand() % 11;

    player.SetGold(player.GetGold() + rewardGold);

    cout << rewardGold << " Gold 획득!\n";

    // 아이템 드랍 확률 30%
    int dropChance = rand() % 100;

    if (dropChance < 30)
    {
        cout << "아이템 획득!\n";
    }
    else
    {
        cout << "아이템 없음\n";
    }
}

bool Battle::IsDead(Character* character)
{
    return character->GetHp() <= 0;
}

void Battle::UsePotion(Player& player)
{
    int healAmount = 50;

    int newHp = player.GetHp() + healAmount;

    // 최대 체력 초과 방지
    if (newHp > player.GetMaxHp())
    {
        newHp = player.GetMaxHp();
    }

    player.SetHP(newHp);

    cout << "포션 사용! HP +50 회복!\n";
}

void Battle::UseAttackItem(Player& player)
{
    int newAttackPower = player.GetAttackPower() + 10;

    player.SetAttackPower(newAttackPower);

    cout << "공격력 증가 아이템 사용! 공격력 +10 증가!\n";
}