// Shop.cpp
#include "Shop.h"

void OpenShop(Character& player)
{
    int choice;

    cout << "========== 상점 ==========\n";
    cout << "보유 골드 : " << player.gold << "\n";
    cout << "1. 체력 회복 (10 Gold)\n";
    cout << "2. 공격력 증가 (20 Gold)\n";
    cout << "3. 상점 나가기\n";

    cin >> choice;

    switch (choice)
    {
        case 1:
        {
            if (player.gold >= 10)
            {
                player.gold -= 10;

                player.hp = player.maxHp;

                cout << "체력을 모두 회복했습니다!\n";
            }
            else
            {
                cout << "골드가 부족합니다!\n";
            }

            break;
        }

        case 2:
        {
            if (player.gold >= 20)
            {
                player.gold -= 20;

                player.attack += 5;

                cout << "공격력이 증가했습니다!\n";
                cout << "현재 공격력 : " << player.attack << "\n";
            }
            else
            {
                cout << "골드가 부족합니다!\n";
            }

            break;
        }

        case 3:
        {
            cout << "상점을 종료합니다.\n";
            break;
        }

        default:
        {
            cout << "잘못된 입력입니다.\n";
            break;
        }
    }
}
