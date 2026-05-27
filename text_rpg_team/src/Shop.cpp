#include "Shop.h"
#include "LogManager.h"
#include <iostream>

void Shop::OpenShop(Player& player)
{
    LogManager::GetInstance().PrintChoice("[상점] 무엇을 구매하시겠습니까?");
	LogManager::GetInstance().PrintMenu("1. 체력 포션  2. 공격력 증가 아이템  3. 나가기");
}

bool Shop::BuyPotion(Player& player)
{
    int potionPrice = 10;

    // 골드가 충분한지 확인
    if (player.GetGold() >= potionPrice)
    {
        // 골드 차감
        player.SetGold(player.GetGold() - potionPrice);

		LogManager::GetInstance().Print("체력 포션을 구매했습니다!");

        return true; 
    }
	LogManager::GetInstance().Print("골드가 부족합니다...");

    return false; // 골드 부족으로 구매 실패
}

bool Shop::BuyAttackItem(Player& player)
{
    int itemPrice = 30;

    // 골드가 충분한지 확인
    if (player.GetGold() >= itemPrice)
    {
        // 골드 차감
        player.SetGold(player.GetGold() - itemPrice);

		LogManager::GetInstance().Print("공격력 증가 포션을 구매했습니다!");

        return true; 
    }

	LogManager::GetInstance().Print("골드가 부족합니다...");

    return false; // 골드 부족으로 구매 실패
}