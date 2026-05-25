#pragma once
#include <string>


class Player;
class Monster;



void Gotoxy(int x, int y);

void DrawBox(int x, int y, int width, int height);

void DrawHellRabbitMonster(int x, int y);

void DrawTitle();

void DrawLayout();

void DrawLog(std::string message);

void DrawChoice(std::string message);

void DrawStatus(Player& player, Monster& monster);

void DrawBattleScene(Player& player, Monster& monster);