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

    int addedAttackPower = 0; // 공격력 아이템 증가 수치를 기억할 변수 추가 (전투 종료 후 원상복구용)

    // TODO 전투 시작 로그

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
        // TODO 전투 승리 로그
        GiveReward(player, monster);
    }
    else
    {
        // TODO 전투 패배 로그
    }
}

void Battle::PlayerTurn(Player& player, Monster& monster, int& addedAttackPower)
{

    // TODO 플레이어 턴 시작 알림

    // 체력 30% 이하일 때 포션 자동 사용
    if (player.GetHp() <= player.GetMaxHp() * 0.3f)
    {
        UsePotion(player);
        // TODO 포션 사용 결과 로그
    }

    // 풀피 상태일 때 공격력 증가 아이템 사용 (전투당 1회만)
    if (player.GetHp() == player.GetMaxHp() && !isAttackItemUsed)
    {
        UseAttackItem(player);
        isAttackItemUsed = true;
        addedAttackPower = 10;
        // TODO 버프 아이템 사용 결과 로그
    }

    // 플레이어가 몬스터를 공격
    player.Attack(&monster);
    // TODO 플레이어 공격 결과 및 몬스터 현재 체력 로그
}

void Battle::MonsterTurn(Player& player, Monster& monster)
{

	// TODO 몬스터 턴 시작 알림
    
    // 몬스터가 플레이어를 공격
    monster.Attack(&player);
	// TODO 몬스터 공격 결과 및 플레이어 현재 체력 로그
}

void Battle::GiveReward(Player& player, Monster& monster)
{
    // 경험치 획득 (고정 50)
    player.SetExp(player.GetExp() + 50);
	// TODO 경험치 획득 로그

    // 골드 획득 (10 ~ 20 랜덤)
    int rewardGold = 10 + rand() % 11;
    player.SetGold(player.GetGold() + rewardGold);
	// TODO 골드 획득 로그

    // 아이템 드랍 확률 30% (로직 흐름 유지를 위해 계산만 진행)
    int dropChance = rand() % 100;
    if (dropChance < 30)
    {
        // TODO 아이템 드랍 성공 로그
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

	// TODO 포션 사용으로 회복된 체력 로그

}

void Battle::UseAttackItem(Player& player)
{
    int newAttackPower = player.GetAttackPower() + 10;
    player.SetAttackPower(newAttackPower);

	// TODO 공격력 증가 아이템 사용으로 증가된 공격력 로그

}