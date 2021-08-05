#ifndef _INCLUDE_H_
#define _INCLUDE_H_
#define BMax 200
#define BLength 3

#include <crtdbg.h>
#include "../ConsoleEx3/ConWrap.h"
#include "mmsystem.h"
#include <windows.h>
#include <time.h>
#include <stdlib.h>


#include "hero.h" // ���� ��������� hero.h ���Ͽ� ���� ��

extern SHero g_Hero; // extern = ��� ������ ��� �����ϰ� ��

#include "bullet.h"

extern SBullet g_Bullet[BMax];

extern DWORD dwBulletFireTime;;

#include "monster.h"

extern SMonster g_Monster[BMax];

extern DWORD dwMonster;

#include "effect.h"

extern Seffect g_Effect[BMax];

extern char effect[BLength][BLength][BLength];





#endif