#include "DXUT.h"
#include "cPlayer.h"
#include "cEnemy.h"
#include <random>
#include "cBullet.h"
#include "cBulletAdmin.h"
#include "cPlayerBullet.h"
#include "cEnemyBullet.h"

cEnemy::cEnemy(){
	_pos.x = rand() % WINSIZEX;
	_pos.y = - 50;
	direction = (rand() % 2);
	oldTime = timeGetTime();
	curTime = timeGetTime();
}
cEnemy::~cEnemy() {

}

void cEnemy::Release() {

}

bool cEnemy::IsCollisionBullet(cBullet* bullet)
{
	RECT re;
	RECT re1 = enemyCollider;
	RECT re2 = bullet->BulletCollider;
	return IntersectRect(&re, &re1, &re2);
}
