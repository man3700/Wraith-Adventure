#pragma once

#include "cBulletAdmin.h"
#include "cPlayer.h"
#include "cBoss.h"
#include "cScroolMap.h"

class cEnemy;

class cEnemyAdmin {
public:
	vector<cEnemy*> m_enemy;
	cBulletAdmin* _bulletAdmin;
	cPlayer* m_player;
	cBoss* m_boss;
	cScroolMap* m_map;
	RECT receiver;

	DWORD startTime;
	DWORD curTime;
	DWORD oldTime0;//Hydra
	DWORD oldTime1;//Scourge
	DWORD oldTime2;//Guardian
	DWORD oldTime3;//Mutalisk

	bool IsBoss;
	bool MakeOnceBoss;
	int repeat0;
	bool IsBegin;
public:
	cEnemyAdmin(cPlayer* _player, cBulletAdmin * _BulletAdmin, cScroolMap* _map);
	~cEnemyAdmin();

	void Update();
	void Render();

	void AddHydra();
	void AddScourge();
	void AddGuardian();
	void AddMutalisk();

	void collisionEnd();
	void collisionBullet();
	void collisionObject();
	void EnemyMaker();

	void hydraLoop(int delay);
	void scourgeLoop(int delay);
	void guardianLoop(int delay);
	void mutaliskLoop(int delay);
};