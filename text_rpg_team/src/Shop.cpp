#include "Shop.h"
#include <iostream>

void Shop::OpenShop(Player& player)
{
    int choice;

    while (true)
    {
        cout << "===== 상점 =====\n";
        cout << "보유 골드 : " << player.GetGold() << "\n";
        cout << "1. 포션 구매 (10 Gold)\n";
        cout << "2. 공격력 증가 아이템 구매 (30 Gold)\n";
        cout << "3. 나가기\n";
        cout << "선택 : ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            BuyPotion(player);
            break;

        case 2:
            BuyAttackItem(player);
            break;

        case 3:
            cout << "상점을 나갑니다.\n";
            return;

        default:
            cout << "잘못된 입력입니다.\n";
            break;
        }
    }
}

void Shop::BuyPotion(Player& player) // 아이템 가격 임의 설정 수정 필요시 수정 가능
{
    int potionPrice = 10;

    if (player.GetGold() >= potionPrice)
    {
        player.SetGold(player.GetGold() - potionPrice);

        cout << "포션 구매 완료!\n";
    }
    else
    {
        cout << "골드가 부족합니다.\n";
    }
}

void Shop::BuyAttackItem(Player& player) // 아이템 가격 임의 설정 수정 필요시 수정 가능
{
    int itemPrice = 30;

    if (player.GetGold() >= itemPrice)
    {
        player.SetGold(player.GetGold() - itemPrice);

        cout << "공격력 증가 아이템 구매 완료!\n";
    }
    else
    {
        cout << "골드가 부족합니다.\n";
    }
}