#include "DXUT.h"
#include "cEnemyAdmin.h"
#include "cBulletAdmin.h"
#include "cEnemy.h"
#include "cBullet.h"
#include "cPlayerBullet.h"
#include "cHydra.h"
#include "cScourge.h"
#include "cGuardian.h"
#include "cMutalisk.h"
#include "cPlayer.h"
#include "cBoss.h"
#include "cScroolMap.h"

#define BossTiming 60000

cEnemyAdmin::cEnemyAdmin(cPlayer* _player, cBulletAdmin* _BulletAdmin, cScroolMap* _map)
	: m_player(_player), _bulletAdmin(_BulletAdmin), m_map(_map)
{
	IsBoss = false;
	IsBegin = false;
	MakeOnceBoss = false;
	curTime = timeGetTime();

	oldTime0 = timeGetTime();//Hydra
	oldTime1 = timeGetTime();//Scourge
	oldTime2 = timeGetTime();//Guardian
	oldTime3 = timeGetTime();//Mutalisk
	repeat0 = 0;
}

cEnemyAdmin::~cEnemyAdmin() {
	for (auto iter : m_enemy)
	{
		SAFE_DELETE(iter);
	}
	m_enemy.clear();
}

void cEnemyAdmin::Update() {
	if (IsBegin == false) { IsBegin = true; startTime = timeGetTime(); }
	for (auto iter : m_enemy)
		iter->Update();

	collisionEnd();
	collisionBullet();
	collisionObject();
	EnemyMaker();
}

void cEnemyAdmin::Render() {
	if (IsBoss) m_boss->Render();

	for (auto iter : m_enemy)
		iter->Render();
}

void cEnemyAdmin::AddHydra()
{
	m_enemy.push_back(new cHydra(_bulletAdmin));
}

void cEnemyAdmin::AddScourge()
{
	m_enemy.push_back(new cScourge(m_player));
}

void cEnemyAdmin::AddGuardian()
{
	m_enemy.push_back(new cGuardian(_bulletAdmin));
}

void cEnemyAdmin::AddMutalisk()
{
	m_enemy.push_back(new cMutalisk(_bulletAdmin, m_player));
}

void cEnemyAdmin::collisionEnd() {
	for (auto iter = m_enemy.begin(); iter != m_enemy.end();) {

		if ((*iter)->_pos.y >= WINSIZEY) {
			SAFE_DELETE(*iter);
			iter = m_enemy.erase(iter);
		}
		else
			++iter;
	}
}

void cEnemyAdmin::collisionBullet()
{
	for (auto iter = m_enemy.begin(); iter != m_enemy.end();)
	{
		for (auto iter2 = _bulletAdmin->m_playerBullet.begin(); iter2 != _bulletAdmin->m_playerBullet.end();)
		{
			if ((*iter)->IsCollisionBullet(*iter2)) // 적 충돌처리 안에 총알 하나하나를 넣어줌
			{
				((*iter)->hp)--;
				
				SAFE_DELETE(*iter2);
				iter2 = _bulletAdmin->m_playerBullet.erase(iter2);
			}
			else iter2++;
		}
		if ((*iter)->hp <= 0)
		{
			SAFE_DELETE(*iter);
			iter = m_enemy.erase(iter);
		}
		else iter++;
	}
}

void cEnemyAdmin::collisionObject() 
{
	if (m_player->hitDelay >= 50) {
		for (auto iter = m_enemy.begin(); iter != m_enemy.end();) {
			if (IntersectRect(&receiver, &(m_player->playerCollider), &((*iter)->enemyCollider))) {
				(m_player->playerHP)--;
				SAFE_DELETE(*iter);
				iter = m_enemy.erase(iter);
				(m_player->hitDelay) = 0;
			}
			else
				++iter;
		}
	}
}

void cEnemyAdmin::EnemyMaker() {
	curTime = timeGetTime();
	
	if(curTime - startTime >= 5000 && curTime - startTime < BossTiming) hydraLoop(2000);
	if (curTime - startTime >= 10000 && curTime - startTime < BossTiming) scourgeLoop(5000);
	if (curTime - startTime >= 20000 && curTime - startTime < BossTiming) guardianLoop(8000);
	if (curTime - startTime >= 35000 && curTime - startTime < BossTiming) mutaliskLoop(8000);

	if (curTime - startTime >= BossTiming && MakeOnceBoss  == false )//60초 후에 보스 생성
	{
		m_map->sceneNum = 1;
		m_boss = new cBoss(m_player,_bulletAdmin);
		IsBoss = true;
		MakeOnceBoss = true;
		for (auto iter : m_enemy)
		{
			SAFE_DELETE(iter);
		}
		m_enemy.clear();
	}

	if (IsBoss) {
		m_boss->Update();
	}
}

void cEnemyAdmin::hydraLoop(int delay) {
	if (curTime - oldTime0 >= delay) {
		AddHydra();
		oldTime0 = timeGetTime();
	}
}

void cEnemyAdmin::scourgeLoop(int delay) {
	//Scourge
	if (curTime - oldTime1 >= delay + (repeat0 * 150)) {
		if (repeat0 <= 4) {
			AddScourge();
			repeat0++;
		}
		else {
			oldTime1 = timeGetTime();
			repeat0 = 0;
		}
	}
}

void cEnemyAdmin::guardianLoop(int delay) {
	//Guardian
	if (curTime - oldTime2 >= delay) {
		AddGuardian();
		oldTime2 = timeGetTime();
	}
}

void cEnemyAdmin::mutaliskLoop(int delay) {
	//Mutalisk
	if (curTime - oldTime3 + (repeat0 * 150) >= delay) {
		AddMutalisk();
		oldTime3 = timeGetTime();
	}
}

