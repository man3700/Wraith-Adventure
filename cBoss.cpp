#include "DXUT.h"
#include "cPlayer.h"
#include "cBoss.h"
#include <random>
#include "cBullet.h"
#include "cBulletAdmin.h"
#include "cPlayerBullet.h"
#include "cEnemyBullet.h"

cBoss::cBoss(cPlayer* _player, cBulletAdmin* _BulletAdmin)
	:_pos(WINSIZEX / 2, 120), ptr_player(_player), ptr_bulletAdmin(_BulletAdmin)
{
	PlaySound(NULL, 0, 0);
	PlaySound(TEXT("./bgm/boss.wav"), NULL, SND_ASYNC | SND_LOOP);
	m_image = IMAGEMANAGER->AddImage("boss", "./image/hatchery/hatchery.png");
	hp = 800;

	startTime = timeGetTime();
	curTime = timeGetTime();

	startT = false;
	Pattern1Checker = 1;
	Pattern1Angle = 0;
	Pattern2Checker = 1;
	Pattern2Angle = 0;
	Pattern3Checker = 1;
}

cBoss::~cBoss() {
	
}

void cBoss::Update() {
	curTime = timeGetTime();
	SetRect(&bossCollider,
		_pos.x - (m_image->info.Width)/4,
		_pos.y - (m_image->info.Height) / 4,
		_pos.x + (m_image->info.Width) / 4,
		_pos.y + (m_image->info.Height) / 4
		);
	checkCollision();
	bossPatternAdmin();
}

void cBoss::Render() {
	m_image->CenterRender(_pos.x, _pos.y);
}

bool cBoss::IsCollisionBullet(cBullet* bullet)
{
	RECT re;
	RECT re1 = bossCollider;
	RECT re2 = bullet->BulletCollider;
	return IntersectRect(&re, &re1, &re2);
}

void cBoss::checkCollision()
{
	//player
	for (auto iter = ptr_bulletAdmin->m_playerBullet.begin(); iter != ptr_bulletAdmin->m_playerBullet.end();)
	{
		if (IsCollisionBullet(*iter)) // 적 충돌처리 안에 총알 하나하나를 넣어줌
		{
			hp--;
			SAFE_DELETE(*iter);
			iter = ptr_bulletAdmin->m_playerBullet.erase(iter);
		}
		else iter++;
	}
}

void cBoss::bossPatternAdmin() {
	if (hp <= 400 && startT == false) { startTime0 = timeGetTime(); startT = true; }
	if (curTime - startTime >= 600 * Pattern1Checker) { Pattern1(); Pattern1Checker++; }
	if (curTime - startTime0 >= 800 * Pattern2Checker && hp <= 400) { Pattern2(); Pattern2Checker++; }
	if (curTime - startTime >= 1500 * Pattern3Checker) { Pattern3(); Pattern3Checker++; }
}

void cBoss::Pattern1() {
	for (float angle = Pattern1Angle; angle < 360 + Pattern1Angle; angle += 20) {
		ptr_bulletAdmin->AddBossBullet(_pos.x, _pos.y, angle);
	}
	Pattern1Angle += 10;
}

void cBoss::Pattern2() {
	for (float angle = Pattern2Angle; angle < 360 + Pattern2Angle; angle += 45) {
		ptr_bulletAdmin->AddBossMissile(_pos.x, _pos.y, angle);
	}
	Pattern2Angle += 5;
}

void cBoss::Pattern3() {
	ptr_bulletAdmin->AddBossArrow(_pos.x, _pos.y, &(ptr_player->player_pos));
}