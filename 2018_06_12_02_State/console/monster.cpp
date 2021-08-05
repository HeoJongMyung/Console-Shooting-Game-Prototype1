#include "Include.h"

void Monster_Init()
{
	for (int i = 0; i < BMax; i++)
	{
		g_Monster[i].x = 0;
		g_Monster[i].y = 0;
		g_Monster[i].attack = 1;
		g_Monster[i].speed = 1;
		g_Monster[i].body = 'Z';
		g_Monster[i].fColor = RED;
		g_Monster[i].bColor = BLACK;
		g_Monster[i].shutup = false;
	}
}

void Monster_Update()
{
	/*if (dwMonster < GetTickCount())
	{
		dwMonster = GetTickCount() + 100;
		for (int i = 0; i < BMax; i++)
		{
			if (g_Monster[i].shutup)
			{
				g_Monster[i].x = random;
				g_Monster[i].y += g_Monster[i].speed;
				g_Monster[i].attack = 1;
				g_Monster[i].speed = 0.1;
				g_Monster[i].body = 'Z';
				g_Monster[i].fColor = BLUE;
				g_Monster[i].bColor = BLACK;
				g_Monster[i].shutup = false;
			}
		}*/

		/*for (int i = 0; i < BMax; i++)
		{
			if (g_Monster[i].y >= 30)
			{
				g_Monster[i].shutup = true;
			}
		}

		for (int i = 0; i < BMax; i++)
		{
			g_Monster[i].y++;
		}*/
		//살아있는 애들 검사 후 내려주기 & 일정 수준 이하로 내려가면 죽이게 만들기
	MonsterRespawn();
	MonsterReuse();
}


void Monster_Draw()
{
	for (int i = 0; i < BMax; i++)
	{
		if (g_Monster[i].shutup)
		{		
		DrawCharEx3(g_Monster[i].x, g_Monster[i].y, g_Monster[i].body, g_Monster[i].fColor, g_Monster[i].bColor);
		}
	}
}

void MonsterReuse()
{
	for (int i = 0; i < BMax; i++)
	{
		g_Monster[i].y += g_Monster[i].speed;
		if (g_Monster[i].shutup == true && g_Monster[i].y > 30)
		{
			g_Monster[i].shutup = false;
			g_Monster[i].y = -100;
			g_Monster[i].x = -100;
		}
	}
}

void MonsterRespawn()
{

	int random = rand() % 120;

	//죽은 애들 검사 후 죽은 애들 살려주기
	if (dwMonster < GetTickCount())
	{
		for (int i = 0; i < BMax; i++)
		{
			if (g_Monster[i].shutup == false)
			{
				g_Monster[i].shutup = true;
				g_Monster[i].y = -1;
				g_Monster[i].x = random;
				dwMonster = GetTickCount() + 100;
				break;
			}
		}
	}
}
