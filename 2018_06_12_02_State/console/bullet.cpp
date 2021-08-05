#include "include.h"

void Bullet_Init() // 총알 초기화
{
	for(int i = 0; i < BMax; i++)
	{
		g_Bullet[i].attack = 1;
		g_Bullet[i].x = 0;
		g_Bullet[i].y = 0;
		g_Bullet[i].speed = 1;
		g_Bullet[i].body = '|';
		g_Bullet[i].fColor = WHITE;
		g_Bullet[i].bColor = BLACK;
		g_Bullet[i].shutup = false;
	}
}



void Bullet_Update()
{
	for (int i = 0; i < BMax; i++)
	{
		g_Bullet[i].y -= g_Bullet[i].speed;
	} 
	Bullet_Noout();
	Bullet_MonsterCollision();
}

void Bullet_Draw()
{
	for (int i = 0; i < BMax; i++)
	{
		if (g_Bullet[i].shutup)
		{
			DrawCharEx3(g_Bullet[i].x, g_Bullet[i].y, g_Bullet[i].body, g_Bullet[i].fColor, g_Bullet[i].bColor); // 플레이어 그리기
		}
	}
}

void Bullet_Noout()
{
	for (int i = 0; i < BMax; i++)
	{
		if (g_Bullet[i].y < 0 && g_Bullet[i].shutup == true)
		{
			g_Bullet[i].shutup = false;
		}
	}
}

void Bullet_Spawn(int x, int y)
{
	if (dwBulletFireTime < GetTickCount()) // 스페이스바 누르면 
	{
		for (int i = 0; i < BMax; i++) // 총알 발사
		{
			if (!g_Bullet[i].shutup) // shutup이 진실이면 if문 실행
			{
				g_Bullet[i].x = x;
				g_Bullet[i].y = y;
				dwBulletFireTime = GetTickCount() + 100;
				g_Bullet[i].shutup = true;
				break;
			}
			//g_Bullet[i].count = 0;
		}

	}

}

void Bullet_MonsterCollision()
{
	for (int i = 0; i < BMax; i++)
	{
		for (int j = 0; j < BMax; j++)
		{
			if (g_Bullet[i].shutup && g_Monster[j].shutup)
			{
				if (g_Bullet[i].x == g_Monster[j].x && g_Bullet[i].y < g_Monster[j].y)
				{
					g_Bullet[i].shutup = false;
					g_Monster[j].shutup = false;
					effect_Screen(g_Bullet[i].x, g_Bullet[i].y);
				}
			}
		}
	}
}