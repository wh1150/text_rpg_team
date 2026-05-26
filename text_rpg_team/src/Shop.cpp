#include "Shop.h"
#include <iostream>

void Shop::OpenShop(Player& player)
{
    // UI 및 입력 루프는 UI 담당 파일에서 처리
}

bool Shop::BuyPotion(Player& player)
{
    int potionPrice = 10;

    // 골드가 충분한지 확인
    if (player.GetGold() >= potionPrice)
    {
        // 골드 차감
        player.SetGold(player.GetGold() - potionPrice);
        return true; // 구매 성공
    }

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
        return true; // 구매 성공
    }

    return false; // 골드 부족으로 구매 실패
}