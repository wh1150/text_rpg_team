#include "UI.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <windows.h>
#include <chrono>
#include <vector>

#include <io.h>
#include <fcntl.h>
using namespace std;




vector<string> titleLine1 = {
    "$$$$$$$$\\ $$$$$$$$\\  $$$$$$\\  $$\\      $$\\         $$\\   $$$$$$\\                  ",
    "\\__$$  __|$$  _____|$$  __$$\\ $$$\\    $$$ |      $$$$ | $$ ___$$\\                 ",
    "   $$ |   $$ |      $$ /  $$ |$$$$\\  $$$$ |      \\_$$ | \\_/   $$ |                ",
    "   $$ |   $$$$$\\    $$$$$$$$ |$$\\$$\\$$ $$ |        $$ |   $$$$$ /                 ",
    "   $$ |   $$  __|   $$  __$$ |$$ \\$$$  $$ |        $$ |   \\___$$\\                 ",
    "   $$ |   $$ |      $$ |  $$ |$$ |\\$  /$$ |        $$ | $$\\   $$ |                ",
    "   $$ |   $$$$$$$$\\ $$ |  $$ |$$ | \\_/ $$ |      $$$$$$\\\\$$$$$$  |                ",
    "   \\__|   \\________|\\__|  \\__|\\__|     \\__|      \\______|\\______/                 "
};

vector<string> titleLine2 = {
    "$$$$$$$$\\ $$$$$$$$\\ $$\\   $$\\ $$$$$$$$\\       $$$$$$$\\  $$$$$$$\\   $$$$$$\\        ",
    "\\__$$  __|$$  _____|$$ |  $$ |\\__$$  __|      $$  __$$\\ $$  __$$\\ $$  __$$\\       ",
    "   $$ |   $$ |      \\$$\\ $$  |   $$ |         $$ |  $$ |$$ |  $$ |$$ /  \\__|      ",
    "   $$ |   $$$$$\\     \\$$$$  /    $$ |         $$$$$$$  |$$$$$$$  |$$ |$$$$\\       ",
    "   $$ |   $$  __|    $$  $$<     $$ |         $$  __$$< $$  ____/ $$ |\\_$$ |      ",
    "   $$ |   $$ |      $$  /\\$$\\    $$ |         $$ |  $$ |$$ |      $$ |  $$ |      ",
    "   $$ |   $$$$$$$$\\ $$ /  $$ |   $$ |         $$ |  $$ |$$ |      \\$$$$$$  |      ",
    "   \\__|   \\________|\\__|  \\__|   \\__|         \\__|  \\__|\\__|       \\______/       "
};

void DrawHellRabbitMonster(int x, int y)
{
    vector<wstring> hellRabbitMonster =
    {
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠔⠂⢄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⠄⠢⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡍⠀⠀⠀⠸⣆⠀⠀⠀⠀⠀⠀⠀⢠⡞⠁⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⠀⢠⢠⡀⠹⠂⠀⠀⠀⠀⠀⢀⠎⠀⠰⡆⠀⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠰⣆⠘⡀⠐⠀⢛⠀⠀⠀⠀⠀⡌⢠⠍⢀⠃⢰⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢆⠱⣯⣿⣸⠛⠓⠀⠐⠛⢃⢮⣷⠎⣠⠏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠘⠃⢀⢠⠲⣂⣶⡈⠃⠿⢧⠆⠀⠀⠀⠀⠀⠋⡼⠿⠘⢧⣐⢀⡰⠆⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⢀⠼⠎⣓⠉⠉⠪⢭⡿⡁⠀⣤⡀⠀⠀⠀⠀⠀⠀⢀⡤⠀⠀⠀⠩⣤⠭⡞⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠘⣄⢀⢺⡟⠀⠀⠼⠧⠂⠀⢿⣿⡶⠀⠀⠠⢴⣾⣿⡿⠀⠀⠀⠀⠹⠄⠀⠀⢶⠊⢹⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠰⡇⠀⠀⠀⠈⢉⣧⣾⣾⣾⣧⣏⠉⠀⠀⠀⠀⠀⠐⠦⣧⡄⡾⠟⠗⠀⣦⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠄⠊⠀⠀⠀⠀⠀⠘⠻⠏⠀⠀⠭⠿⠀⠀⠀⠀⠀⠀⠀⠀⠟⠒⢥⡀⠠⠈⢵⠆⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠨⠄⣦⣤⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⡴⠶⠔⠃⠈⠃⠐⠂⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠛⠛⠛⠘⠳⠆⣤⣤⣤⣤⠀⠶⣿⣷⠴⠶⠇⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
    };

	// 유니코드 출력을 위해 콘솔 모드를 UTF-16으로 변경
    _setmode(_fileno(stdout), _O_U16TEXT);

    for (int i = 0; i < hellRabbitMonster.size(); i++)
    {
        Gotoxy(x, y + i);
        wcout << hellRabbitMonster[i];
    }
	// 출력 후 콘솔 모드를 다시 일반 텍스트로 변경
    _setmode(_fileno(stdout), _O_TEXT);
}


// ==========================================
// 커서를 콘솔의 (x, y) 위치로 이동
// x : 가로 위치, y : 세로 위치
// ==========================================
void Gotoxy(int x, int y)
{
	// COORD는 Windows API에서 좌표를 나타내는 구조체.
    // Windows API의 COORD는 SHORT 타입을 사용.
	// x = 가로 위치, y = 세로 위치를 나타냄.
    COORD pos = { (SHORT)x, (SHORT)y };


    // 콘솔 출력창 (STD_OUTPUT_HANDLE)의 핸들을 가져온 후
    // 커서를 pos 위치로 이동.
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


// ==========================================
// 지정한 위치에 박스 테두리를 그림
// x, y : 박스 시작 위치 (좌상단)
// width : 박스 가로 길이
// height : 박스 세로 길이
// ==========================================
void DrawBox(int x, int y, int width, int height)
{
    // 상단 테두리 출력
    Gotoxy(x, y);
    cout << "┌";
    for (int i = 0; i < width - 2; i++) { cout << "─"; }
    cout << "┐";

    // 좌우 벽 출력
    for (int i = 1; i < height - 1; i++) {
        Gotoxy(x, y + i);
        cout << "│";  // 왼쪽 벽

        Gotoxy(x + width - 1, y + i);
        cout << "│";  // 오른쪽 벽
    }

    // 하단 테두리 출력
    Gotoxy(x, y + height - 1);
    cout << "└";
    for (int i = 0; i < width - 2; i++) { cout << "─"; }
    cout << "┘";
}

void DrawTitle()
{
    // 첫 번째 줄 (TEAM 13)
    for (int i = 0; i < titleLine1.size(); i++) {
        Gotoxy(10, i);
        cout << titleLine1[i];
    }

    // 두 번째 줄 (TEXT RPG)
    for (int i = 0; i < titleLine2.size(); i++) {
        Gotoxy(10, titleLine1.size() + 2 + i);
        cout << titleLine2[i];
    }

    // 플레이어 이름 입력 박스
    int boxY = titleLine1.size() + 2 + titleLine2.size() + 2;
    DrawBox(10, boxY, 60, 5);

}

// ==========================================
// 게임 전체 UI 레이아웃 출력
// 게임 시작 시 한 번만 호출하여 틀을 그림
// 이후 갱신은 각 Draw 함수에서 담당
// ==========================================
void DrawLayout()
{
    system("cls"); // 화면 초기화

    // 박스 레이아웃 배치
    DrawBox(0, 0, 31, 8); // 플레이어 상태창
    DrawBox(31, 0, 31, 8); // 몬스터 상태창
    DrawBox(0, 8, 62, 20); // 전투 화면
    DrawBox(62, 18, 50, 5); // 메뉴창
	DrawBox(62, 23, 50, 5); // 로그창

    // 메뉴 항목 출력
    Gotoxy(63, 21);  cout << "1. 공격  2. 아이템  3. 도망(게임종료) ";
}


void DrawLog(string message)
{
    // 로그 영역 초기화
    Gotoxy(63, 26);
	cout << "                                      ";
    
    // 새 로그 출력
	Gotoxy(63, 26);
	cout << ">> " << message;
}

void DrawChoice(string message)
{
    // 로그 영역 초기화
    Gotoxy(63, 19);
    cout << "                                      ";

    // 새 로그 출력
    Gotoxy(63, 19);
    cout << ">> " << message;
}


void DrawStatus(Player& player, Monster& monster)
{
    // 플레이어 이름 위치
    Gotoxy(2, 0);
    cout << "[" << player.GetName() << "]";

    //플레이어 레벨 위치
	Gotoxy(2, 1);
	cout << "Level: " << player.GetLevel() << "         ";

	// 플레이어 경험치 및 골드 위치
    Gotoxy(2, 2);
    cout << "Exp: " << player.GetExp() << "/100" << "  Gold: " << player.GetGold() << "         ";

    // 플레이어 HP 위치
    Gotoxy(2, 3);
	cout << "HP: " << player.GetHp() << "/" << player.GetMaxHp() << "         ";

	// 플레이어 공격력 위치
    Gotoxy(2, 4);
	cout << "ATK: " << player.GetAttackPower() << "         ";


	// 몬스터 이름 위치
	Gotoxy(33, 0);
	cout << "[" <<  monster.GetName() << "]";

	// 몬스터 HP 위치
	Gotoxy(33, 2);
    cout << "HP: " << monster.GetHp() << "/" << monster.GetMaxHp() << "         ";

	// 몬스터 공격력 위치
	Gotoxy(33, 3);
    cout << "ATK: " << monster.GetAttackPower() << "         ";

}


void DrawBattleScene(Player& player, Monster& monster)
{
    Gotoxy(2, 8);
	cout << "## (" << player.GetName() << ")  VS  (" << monster.GetName() << ") ##";

	DrawHellRabbitMonster(6, 12); // TODO: 임시로 지옥토끼 몬스터를 그려놓은 상태입니다. 추후 몬스터 종류에 따라 다른 그림이 나오도록 변경이 필요합니다.
}