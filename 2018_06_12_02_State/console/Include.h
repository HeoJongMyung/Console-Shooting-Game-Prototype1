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


#include "hero.h" // 위의 헤더파일이 hero.h 파일에 포함 됨

extern SHero g_Hero; // extern = 모든 곳에서 사용 가능하게 함

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