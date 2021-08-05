#include "Include.h"

// 헝가리안 표기법
// int    n이름
// char   c이름
// bool   b이름	
// DWORD  dw이름
// short  s이름
// long   l이름
// 구조체 맴버변수는 
// int m_n이름
// char  m_c이름
// 글로벌 g_?이름
// int nVlaue = 0;
// void Quit();

//int x = 0; // 플레이어 x 위치
//int y = 0; // 플레이어 y 위치

SHero g_Hero;
SBullet g_Bullet[BMax];
SMonster g_Monster[BMax];
Seffect g_Effect[BMax];

DWORD dwBulletFireTime = 0;
DWORD dwMonster = 0;

char effect[BLength][BLength][BLength] = {

	{' ',' ',' '
	,' ','*',' '
	,' ',' ',' '},

	{' ','*',' '
	,'*',' ','*'
	,' ','*',' '},

	{'*',' ','*'
	,' ',' ',' '
	,'*',' ','*'}
};

int main()
{
	srand(time(NULL));
	Hero_Init();
	Bullet_Init();
	Monster_Init();
	effect_Init();
	
	InitialConsole();//초기화함수
	SetWindowTitle("Shooting"); // 콘솔 이름

	while (true)
	{
		CheckInput();
		ClearScreenEx3(BLACK);

		Hero_Update();
		Hero_Draw();
		Hero_Noout();

		Bullet_Update();
		Bullet_Draw();
		Bullet_Noout();

		Monster_Update();
		Monster_Draw();

		effect_Update();
		effect_Draw();

		Flip(); // 더블 버퍼링: 미리 저장 후 보여주는거 ex)네이버 웹툰 미리보기?
		EngineSync(30);
	}
	ReleaseConsole();
	return 0;
}
