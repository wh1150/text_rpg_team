#include "UI.h"
#include "Player.h"
#include "Monster.h"
#include <iostream>
#include <windows.h>
#include <chrono>
#include <vector>
#include <string>

#include <io.h>
#include <fcntl.h>


#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
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

void DrawMonster(int x, int y, Monster& monster)
{
    vector<wstring> selectedMonster;

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

    vector<wstring> crazyChihuahuaMonster =
    {
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⠤⢤⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⡤⠄⢤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠇⠈⠀⠊⢙⠆⣄⠀⠀⠀⠀⢰⢇⣦⠀⠀⠀⠀⠀⡴⠃⠱⠀⠁⢠⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠀⠀⠀⠈⠡⡈⠓⠀⣀⠠⠼⠉⠙⠣⢀⣀⡴⠂⠴⠀⠀⠀⠀⡈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢃⠀⠀⠐⡂⢥⠀⠛⠀⠀⠀⠀⠀⠀⢀⡈⢀⡘⠔⡒⠀⠀⠠⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠳⡄⡰⡜⡜⢀⣄⠀⠀⠀⠀⠀⠀⠈⢃⡀⠹⠘⡀⠀⠀⠁⢠⡄⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⢘⡉⠵⣠⡙⠧⠀⠀⡜⠉⠰⢄⠀⠈⠁⣠⠰⠋⠹⠆⢀⠥⠚⣡⢆⠃⡀⠽⠧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡀⠀⠑⠒⠲⠋⣙⠇⠀⢥⡀⢉⡰⢠⣤⣶⢧⡈⢀⡼⠃⠀⢏⡈⠁⠖⠀⠛⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡲⢄⠀⠀⠀⠀⠈⢃⡄⠀⠀⢨⡰⣌⣿⣯⡀⡄⠈⠀⣀⡌⠏⢀⡀⠀⠀⠖⠓⣝⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⡞⠐⠃⠈⡜⡄⠀⠀⠀⠈⢈⢷⣦⢸⣷⣿⣿⣿⡿⣷⣰⡴⢿⠀⣀⣟⣇⠀⢠⢣⠻⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠣⣀⠀⢀⡐⠁⠀⠀⠀⠀⠨⢹⠿⣏⣪⣌⣉⣹⣧⡫⡛⠃⣭⠱⠀⢽⡧⠀⠌⠄⠀⠀⢂⠜⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠈⢠⣬⡐⠉⠭⠉⠋⠀⢄⠀⣿⠀⣿⢅⠠⠇⠊⠀⠘⡇⠈⢨⠃⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⣸⣏⣄⡿⠂⠁⠛⠶⠆⠘⠛⣿⡀⢹⣷⠸⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠈⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠈⠁⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
    };

    vector<wstring> shadowCatMonster =
    {
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠴⣠⢀⠀⠀⠀⡄⠘⢷⣦⠀⠀⢰⣿⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⠀⠀⠀⠀⠀⢀⣿⣿⣧⣦⠀⠁⠘⠋⢁⠠⣺⣿⣿⡇⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠐⣲⠀⠀⠀⠀⠘⢻⣿⣿⣿⣯⣺⣶⣿⣿⣼⣿⣿⣿⣿⠀⠀⠀⠀⠀⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠇⠲⡤⠀⠀⠀⠉⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠃⠐⠂⠀⢀⠃⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⡆⢀⠀⠰⡄⠀⢀⠐⢥⣿⣿⢿⣿⣿⣿⣿⣿⣿⣿⠋⣿⣿⣶⣿⠄⠀⠰⠈⢀⢀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⢘⣂⠄⠁⠀⠐⠫⣷⣿⣿⣧⡉⡿⢿⣿⣿⣋⣉⣼⣿⣿⡯⡢⠀⢠⠒⢁⣀⠠⠄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣄⡁⠀⠕⣿⣿⣿⣟⡾⢿⠿⢿⣻⣫⣿⣿⠟⠀⠀⠀⠘⣀⡃⣌⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⠋⠙⣿⣿⠀⢀⠈⠉⣹⣻⣿⣿⣾⣿⣿⣿⣿⣿⣦⢠⣄⠄⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢤⣿⣿⣾⠋⠀⠀⣸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣤⡦⠆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣚⣿⣿⣿⣧⣿⣿⣽⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠣⠂⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⠉⠉⠻⠟⠁⢈⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀",
        L"⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠋⠛⠛⠉⠛⠛⠛⠛⠉⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
    };

    if (monster.GetName() == "Hell Rabbit")
    {
        selectedMonster = hellRabbitMonster;
    }
    else if (monster.GetName() == "Crazy Chihuahua")
    {
        selectedMonster = crazyChihuahuaMonster;
    }
    else if (monster.GetName() == "Shadow Cat")
    {
        selectedMonster = shadowCatMonster;
    }


	// 유니코드 출력을 위해 콘솔 모드를 UTF-16으로 변경
    (void)_setmode(_fileno(stdout), _O_U16TEXT);

    for (int i = 0; i < selectedMonster.size(); i++)
    {
        Gotoxy(x, y + i);
        wcout << selectedMonster[i];
    }
	// 출력 후 콘솔 모드를 다시 일반 텍스트로 변경
    (void)_setmode(_fileno(stdout), _O_TEXT);
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
    for (size_t i = 0; i < titleLine1.size(); i++) {
        Gotoxy(10, i);
        cout << titleLine1[i];
    }

    // 두 번째 줄 (TEXT RPG)
    for (size_t i = 0; i < titleLine2.size(); i++) {
        Gotoxy(10, titleLine1.size() + 2 + i);
        cout << titleLine2[i];
    }

    // 플레이어 이름 입력 박스
    int boxY = static_cast<int>(titleLine1.size() + 2 + titleLine2.size() + 2);
    DrawBox(10, boxY, 60, 5);

}

// ==========================================
// 게임 전체 UI 레이아웃 출력
// 게임 시작 시 한 번만 호출하여 틀을 그림
// 이후 갱신은 각 Draw 함수에서 담당
// ==========================================
void DrawLayout()
{

    // 박스 레이아웃 배치
    DrawBox(0, 0, 31, 8); // 플레이어 상태창
    DrawBox(31, 0, 31, 8); // 몬스터 상태창
    DrawBox(0, 8, 62, 20); // 전투 화면
    DrawBox(62, 18, 52, 5); // 메뉴창
	DrawBox(62, 23, 52, 5); // 로그창
    DrawBox(62, 10, 52, 8); // 인벤토리창
    DrawBox(62, 0, 52, 10); // 상점창

    // 인벤토리 창 제목 출력
	Gotoxy(63, 11);  cout << YELLOW << "[인벤토리]" << RESET;


	Gotoxy(63, 1);  cout << YELLOW << "[상점]" << RESET;
}


vector<string> logs;

void DrawLog(string message)
{
    const int logX = 63;
    const int logY = 24;
    const int logWidth = 49;
    const int logMaxCount = 3;

    logs.push_back(message);

    if (logs.size() > logMaxCount)
    {
        logs.erase(logs.begin());
    }

    for (int i = 0; i < logMaxCount; i++)
    {
        Gotoxy(logX, logY + i);
        cout << string(logWidth, ' ');
    }

    for (int i = 0; i < logs.size(); i++)
    {
        Gotoxy(logX, logY + i);
        cout << ">> " << logs[i];
    }

    //Sleep(1000);
}

void DrawChoice(string message)
{
    // 로그 영역 초기화
    Gotoxy(63, 19);
    cout << "                                                  ";

    // 새 로그 출력
    Gotoxy(63, 19);
    cout << ">> " << message;

}

void DrawMenu(string message)
{
    // 로그 영역 초기화
    Gotoxy(63, 21);
    cout << "                                                  ";

    // 새 로그 출력
    Gotoxy(63, 21);
    cout << ">> " << message;

    // 메뉴 항목 출력
    // Gotoxy(63, 21);  cout << "1. 공격  2. 아이템  3. 도망(게임종료) ";
}


void DrawStatus(Player& player, Monster& monster)
{
    // 플레이어 이름 위치
    Gotoxy(2, 1);
    cout << YELLOW << "[" << player.GetName() << "]" << RESET;

    //플레이어 레벨 위치
	Gotoxy(2, 2);
	cout <<"Level: " << player.GetLevel() << "         ";

	// 플레이어 경험치 및 골드 위치
    Gotoxy(2, 3);
    cout << GREEN << "Exp: " << RESET << player.GetExp() << "/100" << YELLOW << "  Gold: " << RESET << player.GetGold() << "   ";

    // 플레이어 HP 위치
    Gotoxy(2, 4);
	cout << RED << "HP: " << RESET << player.GetHp() << "/" << player.GetMaxHp() << "         ";

	// 플레이어 공격력 위치
    Gotoxy(2, 5);
	cout << BLUE << "ATK: " << RESET << player.GetAttackPower() << "         ";


	// 몬스터 이름 위치
	Gotoxy(33, 1);
	cout << YELLOW << "[" <<  monster.GetName() << "]" << RESET;

	// 몬스터 HP 위치
	Gotoxy(33, 2);
    cout << RED << "HP: " << RESET << monster.GetHp() << "/" << monster.GetMaxHp() << "         ";

	// 몬스터 공격력 위치
	Gotoxy(33, 3);
    cout << BLUE << "ATK: "<< RESET << monster.GetAttackPower() << "         ";

}


void DrawBattleScene(Player& player, Monster& monster)
{
    static int offset = 0;
    static int dir = 1;

    Gotoxy(2, 9);
	cout << YELLOW << "##" << RESET << " [" << player.GetName() << "]" << RED << "  VS  " << RESET << "[" << monster.GetName() << "] " << YELLOW << "##" << RESET;

    ClearMonsterArea(4, 12, 56, 13);
	DrawMonster(6 + offset, 12, monster);
    offset += dir;
    if (offset >= 1 || offset <= -1)
    {
        dir *= -1;
	}
}


void DrawInventory(const std::vector<std::string>& items)
{
  // 인벤토리 영역(63, 12)부터 출력 시작
     for (int i = 0; i < 5; i++) { // 상자 높이에 맞춰 최대 5개 출력
         Gotoxy(63, 12 + i);
         cout << "                                              "; // 기존 내용 지우기
         if (i < items.size())
         {
             Gotoxy(63, 12 + i);
             cout << GREEN << i + 1 << ". " << items[i] << RESET;
         }
         else if (i == 0 && items.empty())
         {
             Gotoxy(63, 12);
			 cout << BLUE << "인벤토리가 비어있습니다." << RESET;
         }
     }
}

void DrawShop()
{
    Gotoxy(63, 3);
	cout << GREEN<< "[ 체력 포션 ]" << RESET << " (10 Gold)";

	Gotoxy(63, 6);
    cout << GREEN << "[ 공격력 증가 포션 ]" << RESET << " (30 Gold)";
}

void ClearMonsterArea(int x, int y, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        Gotoxy(x, y + i);
        cout << string(width, ' ');
    }
}