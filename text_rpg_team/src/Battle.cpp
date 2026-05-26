#include "Battle.h"
#include "LogManager.h"
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

    int addedAttackPower = 0; // 공격력 아이템 증가 수치를 기억할 변수 추가 (전투 종료 후 원상복구용)

    LogManager::GetInstance().Print("전투를 시작합니다!                 ");

    // 전투 루프 (둘 중 하나가 죽을 때까지)
    while (!IsDead(&player) && !IsDead(&monster))
    {
        PlayerTurn(player, monster, addedAttackPower);

        if (!IsDead(&monster))
        {
            MonsterTurn(player, monster);
        }
    }

    // 전투 종료 후 아이템으로 올린 공격력 원상복구
    if (isAttackItemUsed && addedAttackPower > 0)
    {
        player.SetAttackPower(player.GetAttackPower() - addedAttackPower);
    }

    // 전투 종료 후 승리 시 보상 처리
    if (!IsDead(&player))
    {
        GiveReward(player, monster);
        LogManager::GetInstance().Print("전투 승리!                 ");
    }
    else
    {
        LogManager::GetInstance().Print("전투 패배! 플레이어는 나약합니다.    ");
    }
}

void Battle::PlayerTurn(Player& player, Monster& monster, int& addedAttackPower)
{
    // 체력 30% 이하일 때 포션 자동 사용
    if (player.GetHp() <= player.GetMaxHp() * 0.3f)
    {
         
        UsePotion(player); // TODO: 아이템 클래스 구현 완료 시 player.UseItem() 등으로 대체
        LogManager::GetInstance().Print("위험! 자동 포션을 사용합니다.  ");
    }

    // 풀피 상태일 때 공격력 증가 아이템 사용 (전투당 1회만)
    if (player.GetHp() == player.GetMaxHp() && !isAttackItemUsed)
    {
        UseAttackItem(player); // TODO: 아이템 클래스 구현 완료 시 player.UseItem() 등으로 대체 예정
        isAttackItemUsed = true;
        addedAttackPower = 10;
        LogManager::GetInstance().Print("공격력 강화 포션을 사용합니다.  ");

    }

    // 플레이어가 몬스터를 공격
    player.Attack(&monster);
    LogManager::GetInstance().PrintAttack(player, monster);
}

void Battle::MonsterTurn(Player& player, Monster& monster)
{
    monster.Attack(&player);
    LogManager::GetInstance().PrintAttack(monster, player);

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
    std::string itemName = ""; // 임의로 추가합니다. 추후 변경해야합니다.
    if (dropChance < 30)
    {
        // TODO: 아이템 이름을 변수에 담아주세요. 아이템이 있다면 아이템이름을 출력하게 됩니다. 없다면 ""으로 넣어주세요.
        itemName = "체력 포션";
    }
    LogManager::GetInstance().PrintReward(player, monster, rewardGold, itemName);
}

bool Battle::IsDead(Character* character)
{
    return character->GetHp() <= 0;
}

