#include "include.h"

void Hero_Init()
{
	g_Hero.attack = 1;
	g_Hero.x = 1;
	g_Hero.y = 1;
	g_Hero.speed = 1;
	g_Hero.body = 'A';
	g_Hero.hp = 5;
	g_Hero.fColor = WHITE;
	g_Hero.bColor = BLACK;
}

void Hero_Update()
{
	if (IsKey(VK_LEFT) || IsKey(VK_A))
	{
		g_Hero.x -= g_Hero.speed;
	}

	if (IsKey(VK_RIGHT) || IsKey(VK_D))
	{
		g_Hero.x += g_Hero.speed;;
	}

	if (IsKey(VK_UP) || IsKey(VK_W))
	{
		g_Hero.y -= g_Hero.speed;;
	}

	if (IsKey(VK_DOWN) || IsKey(VK_S))
	{
		g_Hero.y += g_Hero.speed;;
	}

	if (IsKey(VK_SPACE))
	{
		Bullet_Spawn(g_Hero.x, g_Hero.y);
	}
}

void Hero_Draw()
{
	DrawCharEx3(g_Hero.x, g_Hero.y, g_Hero.body, g_Hero.fColor, g_Hero.bColor); // 플레이어 그리기
}

void Hero_Noout()
{
	if (g_Hero.x <= 0)
	{
		g_Hero.x = 0;
	}

	if (g_Hero.x >= 119)
	{
		g_Hero.x = 119;
	}

	if (g_Hero.y <= 0)
	{
		g_Hero.y = 0;
	}

	if (g_Hero.y >= 29)
	{
		g_Hero.y = 29;
	}
}