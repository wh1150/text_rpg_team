#include "Shop.h"
#include "LogManager.h"
#include "Item.h"
#include "HealthPotion.h"
#include "AttackBoost.h"
#include <iostream>
#include <conio.h>
#include <memory>


#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"

void Shop::OpenShop(Player& player)
{
    char choice;

    while (true)
    {
        LogManager::GetInstance().PrintMenu(GREEN "1. 체력 포션 " BLUE "2. 공격력 증가 아이템" RED  " 3. 나가기" RESET);
        LogManager::GetInstance().PrintChoice(YELLOW "[상점]" RESET " 무엇을 구매하시겠습니까?");
	    
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
            LogManager::GetInstance().Print(GREEN "전장으로 돌아갑니다." RESET);
            return;

        default:
            LogManager::GetInstance().PlayFalseSound();
            LogManager::GetInstance().Print(YELLOW "잘못된 입력입니다. 다시 선택해주세요." RESET);
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
		LogManager::GetInstance().Print(GREEN "체력 포션을 구매했습니다!" RESET);
        LogManager::GetInstance().PrintInventory(player.GetInventory());
        LogManager::GetInstance().PrintStatus();

        return true; 
    }
    LogManager::GetInstance().PlayFalseSound();
	LogManager::GetInstance().Print(YELLOW "골드가 부족합니다..." RESET);

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
		LogManager::GetInstance().Print(GREEN "공격력 증가 포션을 구매했습니다!" RESET);
        LogManager::GetInstance().PrintInventory(player.GetInventory());
        LogManager::GetInstance().PrintStatus();

        return true; 
    }
    LogManager::GetInstance().PlayFalseSound();
	LogManager::GetInstance().Print(YELLOW "골드가 부족합니다..." RESET);

    return false; // 골드 부족으로 구매 실패
}