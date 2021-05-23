#pragma once
class cBoss
{
public:
	texture* m_image;

	cPlayer* ptr_player;
	cBulletAdmin* ptr_bulletAdmin;

	DWORD startTime;
	DWORD startTime0;
	bool startT;
	DWORD curTime;

	RECT bossCollider;
	D3DXVECTOR2 _pos;
	int hp;
	
	int Pattern1Checker;
	int Pattern1Angle;
	int Pattern2Checker;
	int Pattern2Angle;
	int Pattern3Checker;
public:
	cBoss(cPlayer* _player, cBulletAdmin* _BulletAdmin);
	~cBoss();

	void Update();
	void Render();

	bool IsCollisionBullet(cBullet* bullet);
	void checkCollision();

	void bossPatternAdmin();
	void Pattern1();//원형 발사
	void Pattern2();//유도 미사일 발사
	void Pattern3();//폭발탄 발사
};