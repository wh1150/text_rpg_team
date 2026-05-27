#include "Shop.h"
#include "LogManager.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <iostream>
#include <conio.h>
#include <memory>

void Shop::OpenShop(Player& player)
{
    char choice;

    while (true)
    {
        LogManager::GetInstance().PrintMenu("1. 체력 포션  2. 공격력 증가 아이템  3. 나가기");
        LogManager::GetInstance().PrintChoice("[상점] 무엇을 구매하시겠습니까?");
	    
        choice = _getch();

        switch (choice)
        {
        case '1':
            BuyPotion(player);
            break;

        case '2':
            BuyAttackItem(player);
            break;

        case '3':
            LogManager::GetInstance().PlaySelectSound();
            LogManager::GetInstance().Print("전장으로 돌아갑니다.");
            return;

        default:
            LogManager::GetInstance().PlayFalseSound();
            LogManager::GetInstance().Print("잘못된 입력입니다. 다시 선택해주세요.");
            break;
        }
    }
}

bool Shop::BuyPotion(Player& player)
{
    int potionPrice = 10;

    // 골드가 충분한지 확인
    if (player.GetGold() >= potionPrice)
    {
        // 골드 차감
        player.SetGold(player.GetGold() - potionPrice);

        player.AddItem(std::make_unique<HealthPotion>());
        LogManager::GetInstance().PlaySelectSound();
		LogManager::GetInstance().Print("체력 포션을 구매했습니다!");
        LogManager::GetInstance().PrintInventory(player.GetInventory());
        LogManager::GetInstance().PrintStatus();

        return true; 
    }
    LogManager::GetInstance().PlayFalseSound();
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

        player.AddItem(std::make_unique<AttackBoost>());
        LogManager::GetInstance().PlaySelectSound();
		LogManager::GetInstance().Print("공격력 증가 포션을 구매했습니다!");
        LogManager::GetInstance().PrintInventory(player.GetInventory());
        LogManager::GetInstance().PrintStatus();

        return true; 
    }
    LogManager::GetInstance().PlayFalseSound();
	LogManager::GetInstance().Print("골드가 부족합니다...");

    return false; // 골드 부족으로 구매 실패
}