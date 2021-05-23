#pragma once

class cBullet;
class cBulletEnemy;
class cBulletAdmin
{
public:
	vector<cBullet*> m_playerBullet;
	vector<cBullet*> m_enemyBullet;
public:
	cBulletAdmin();
	~cBulletAdmin();

	void Reset();

	void Update();
	void Render();

	void AddEnemyBullet(int _xPos, int _yPos);
	void AddHugeBullet(int _xPos, int _yPos);
	void AddEnemyMissile(int _xPos, int _yPos, D3DXVECTOR2* _pos);
	void AddPlayerBullet(int _xPos, int _yPos, float _angle);
	void AddBossBullet(int _xPos, int _yPos, float _angle);
	void AddBossMissile(int _xPos, int _yPos, float _angle);
	void AddBossArrow(int _xPos, int _yPos, D3DXVECTOR2* _pos);

	void CheckCollision();
};

