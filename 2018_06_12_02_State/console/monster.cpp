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
		//����ִ� �ֵ� �˻� �� �����ֱ� & ���� ���� ���Ϸ� �������� ���̰� �����
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

	//���� �ֵ� �˻� �� ���� �ֵ� ����ֱ�
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
