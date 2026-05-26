#pragma once
#include <string>
#include <vector>


class Player;
class Monster;



void Gotoxy(int x, int y);

void DrawBox(int x, int y, int width, int height);

void DrawMonster(int x, int y, Monster& monster);

void DrawTitle();

void DrawLayout();

void DrawLog(std::string message);

void DrawChoice(std::string message);

void DrawMenu(std::string message);

void DrawStatus(Player& player, Monster& monster);

void DrawBattleScene(Player& player, Monster& monster);

void DrawInventory(const std::vector<std::string>& items);