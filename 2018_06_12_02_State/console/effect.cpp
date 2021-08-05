#include "include.h"

void effect_Init()
{
	for (int i = 0; i < BMax; i++)
	{
		g_Effect[i].x = 0;
		g_Effect[i].y = 0;
		g_Effect[i].fColor = WHITE;
		g_Effect[i].bColor = BLACK;
		g_Effect[i].shutup = false;	
		g_Effect[i].index = 0;
		g_Effect[i].NextEffect = 0;
	}
}


void effect_Update()
{
	for (int i = 0; i < BMax; i++)
	{
		if (g_Effect[i].shutup)
		{
			if (g_Effect[i].NextEffect < GetTickCount())
			{
				g_Effect[i].index++;
				g_Effect[i].NextEffect = GetTickCount() + 500;
			}

			if (g_Effect[i].index > 2)
			{
				g_Effect[i].shutup = false;
			}
		}
	}
}

void effect_Draw()
{
	for (int i = 0; i < BMax; i++)
	{
		if (g_Effect[i].shutup)
		{
			DrawCharEx3(g_Effect[i].x - 1, g_Effect[i].y - 1, effect[g_Effect[i].index][0][0], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x, g_Effect[i].y - 1, effect[g_Effect[i].index][0][1], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x + 1, g_Effect[i].y - 1, effect[g_Effect[i].index][0][2], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x - 1, g_Effect[i].y, effect[g_Effect[i].index][1][0], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x, g_Effect[i].y, effect[g_Effect[i].index][1][1], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x + 1, g_Effect[i].y, effect[g_Effect[i].index][1][2], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x - 1, g_Effect[i].y + 1, effect[g_Effect[i].index][2][0], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x, g_Effect[i].y + 1, effect[g_Effect[i].index][2][1], g_Effect[i].fColor, g_Effect[i].bColor);
			DrawCharEx3(g_Effect[i].x + 1, g_Effect[i].y + 1, effect[g_Effect[i].index][2][2], g_Effect[i].fColor, g_Effect[i].bColor);
		}
	}
}

void effect_Screen(int x, int y)
{
	for (int i = 0; i < BMax; i++)
	{
		 if(g_Effect[i].shutup == false)
		{
			g_Effect[i].x = x;
			g_Effect[i].y = y;
			g_Effect[i].index = 0;
			g_Effect[i].NextEffect = GetTickCount() + 500;
			g_Effect[i].shutup = true;
			break;
		}
	}
}