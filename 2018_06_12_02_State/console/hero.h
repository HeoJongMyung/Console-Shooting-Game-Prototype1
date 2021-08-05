#pragma once


struct SHero
{
	int x, y;
	char body;
	int attack;
	int speed;
	int hp;

	DWORD fColor;
	DWORD bColor;
};

void Hero_Init();

void Hero_Update();

void Hero_Draw();

void Hero_Noout();