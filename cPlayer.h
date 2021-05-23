#pragma once
#include "cBulletAdmin.h"

class cPlayer
{
public:
	texture* playerImage[2];
	texture* skillImage[2];
	texture* gameover;
	texture* heart[2];

	D3DXVECTOR2 player_pos;
	RECT playerCollider;
	cBulletAdmin* ptr_bulletAdmin;
	RECT receiver;

	DWORD curTime;
	DWORD oldTime;

	int shootDelay;
	int skillDelay;
	int hitDelay;
	int shiftMove;
	int playerHP;
	bool playOnce;
public:
	cPlayer(cBulletAdmin* _bulletAdmin);
	~cPlayer();

	void Update();
	void Render();

	bool IsCollisionEnemyBullet(cBullet* enemyB);
	void CollisionBullet();

	/*
	bool IsCollisionEnemy(cEnemy* enemy);
	void EnemyCollision();
	bool IsCollisionEnemyBullet(cBullet* enemyB);
	void EnemyBulletCollision();
	*/
};

