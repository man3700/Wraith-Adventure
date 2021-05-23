#pragma once
#include "cPlayerBullet.h"
#include "cPlayer.h"

class cEnemy {
public:
	vector<texture*>* textures;
	texture* m_image;
	DWORD oldTime;
	DWORD curTime;
	RECT enemyCollider;
	D3DXVECTOR2 _pos;
	bool direction;
	int hp;
	int cnt;
public:
	cEnemy();
	virtual ~cEnemy();

	virtual void Update() PURE;
	virtual void Render() PURE;

	void Release();
	bool IsCollisionBullet(cBullet* bullet);
};

