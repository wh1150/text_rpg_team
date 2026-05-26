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

    // 전투 루프 (둘 중 하나가 죽을 때까지)
    while (!IsDead(&player) && !IsDead(&monster))
    {
        PlayerTurn(player, monster);

        if (!IsDead(&monster))
        {
            MonsterTurn(player, monster);
        }
    }

    // 전투 종료 후 승리 시 보상 처리
    if (!IsDead(&player))
    {
        GiveReward(player, monster);
    }
}

void Battle::PlayerTurn(Player& player, Monster& monster)
{
    // 체력 30% 이하일 때 포션 자동 사용
    if (player.GetHp() <= player.GetMaxHp() * 0.3f)
    {
        UsePotion(player);
    }

    // 풀피 상태일 때 공격력 증가 아이템 사용 (전투당 1회만)
    if (player.GetHp() == player.GetMaxHp() && !isAttackItemUsed)
    {
        UseAttackItem(player);
        isAttackItemUsed = true;
    }

    // 플레이어가 몬스터를 공격
    player.Attack(&monster);
}

void Battle::MonsterTurn(Player& player, Monster& monster)
{
    // 몬스터가 플레이어를 공격
    monster.Attack(&player);
}

void Battle::GiveReward(Player& player, Monster& monster)
{
    // 경험치 획득 (고정 50)
    player.SetExp(player.GetExp() + 50);

    // 골드 획득 (10 ~ 20 랜덤)
    int rewardGold = 10 + rand() % 11;
    player.SetGold(player.GetGold() + rewardGold);

    // 아이템 드랍 확률 30% (로직 흐름 유지를 위해 계산만 진행)
    int dropChance = rand() % 100;
    if (dropChance < 30)
    {
        // TODO: 향후 아이템 인벤토리 추가 로직이 필요하다면 여기에 작성
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
}

void Battle::UseAttackItem(Player& player)
{
    int newAttackPower = player.GetAttackPower() + 10;
    player.SetAttackPower(newAttackPower);
}