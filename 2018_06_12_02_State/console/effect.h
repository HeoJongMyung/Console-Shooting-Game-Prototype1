#pragma once
struct Seffect
{
	int x, y;
	int index;
	bool shutup;

	DWORD fColor;
	DWORD bColor;
	DWORD NextEffect;
};

void effect_Init();

void effect_Update();

void effect_Draw();

void effect_Screen(int x, int y);


