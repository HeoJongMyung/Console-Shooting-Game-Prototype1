#pragma once

struct SMonster
{
	int x, y;
	int attack;
	int speed;
	char body;
	bool shutup;


	DWORD fColor;
	DWORD bColor;
};

void Monster_Init();

void Monster_Update();

void Monster_Draw();

void MonsterRespawn(); 

void MonsterReuse(); 
