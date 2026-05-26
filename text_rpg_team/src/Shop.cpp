#include "Shop.h"
#include <iostream>

void Shop::OpenShop(Player& player)
{
	// TODO 상점 입장 로그
}

bool Shop::BuyPotion(Player& player)
{
    int potionPrice = 10;

    // 골드가 충분한지 확인
    if (player.GetGold() >= potionPrice)
    {
        // 골드 차감
        player.SetGold(player.GetGold() - potionPrice);

		// TODO 포션 구매 성공 로그

        return true; 
    }
	// TODO 포션 구매 실패 로그

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

		// TODO 공격력 증가 아이템 구매 성공 로그

        return true; 
    }

	// TODO 공격력 증가 아이템 구매 실패 로그

    return false; // 골드 부족으로 구매 실패
}