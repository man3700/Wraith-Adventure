#include "DXUT.h"
#include "cBulletAdmin.h"
#include "cEnemyBullet.h"
#include "cEnemyHugeBullet.h"
#include "cEnemyMissile.h"
#include "cPlayerBullet.h"
#include "cBossBullet.h"
#include "cBossMissile.h"
#include "cBossArrow.h"
#include "cBullet.h"

cBulletAdmin::cBulletAdmin()
{
}


cBulletAdmin::~cBulletAdmin()
{
	Reset();
}

void cBulletAdmin::Reset()
{
	for (auto iter : m_playerBullet)
		SAFE_DELETE(iter);
	m_playerBullet.clear();
	for (auto iter : m_enemyBullet)
		SAFE_DELETE(iter);
	m_enemyBullet.clear();
}

void cBulletAdmin::Update()
{
	for (auto iter : m_playerBullet)
		iter->Update();
	for (auto iter : m_enemyBullet)
		iter->Update();
	CheckCollision();
}

void cBulletAdmin::Render()
{
	for (auto iter : m_playerBullet)
		iter->Render();
	for (auto iter : m_enemyBullet)
		iter->Render();
}

void cBulletAdmin::AddEnemyBullet(int _xPos, int _yPos) {
	m_enemyBullet.push_back(new cEnemyBullet(_xPos, _yPos));
}

void cBulletAdmin::AddHugeBullet(int _xPos, int _yPos) {
	m_enemyBullet.push_back(new cEnemyHugeBullet(_xPos, _yPos));
}

void cBulletAdmin::AddEnemyMissile(int _xPos, int _yPos, D3DXVECTOR2* _pos)
{
	m_enemyBullet.push_back(new cEnemyMissile(_xPos, _yPos, _pos));
}

void cBulletAdmin::AddPlayerBullet(int _xPos, int _yPos, float _angle) {
	m_playerBullet.push_back(new cPlayerBullet(_xPos, _yPos, _angle));
}

void cBulletAdmin::AddBossBullet(int _xPos, int _yPos, float _angle) {
	m_enemyBullet.push_back(new cBossBullet(_xPos, _yPos, _angle));
}

void cBulletAdmin::AddBossMissile(int _xPos, int _yPos, float _angle) {
	m_enemyBullet.push_back(new cBossMissile(_xPos, _yPos, _angle));
}

void cBulletAdmin::AddBossArrow(int _xPos, int _yPos, D3DXVECTOR2* _pos) {
	m_enemyBullet.push_back(new cBossArrow(_xPos, _yPos, _pos));
}

void cBulletAdmin::CheckCollision()
{
	//player
	for (auto iter = m_playerBullet.begin(); iter != m_playerBullet.end();) {
		if ((*iter)->IsOutMap()) {
			SAFE_DELETE(*iter);
			iter = m_playerBullet.erase(iter);
		}
		else ++iter;
	}

	//enemy
	for (auto iter = m_enemyBullet.begin(); iter != m_enemyBullet.end();) {
		if ((*iter)->IsOutMap()) {
			SAFE_DELETE(*iter);
			iter = m_enemyBullet.erase(iter);
		}
		else ++iter;
	}
}