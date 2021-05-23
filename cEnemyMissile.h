#pragma once
#include "cBullet.h"
#include "cPlayer.h"

class cEnemyMissile : public cBullet
{
private:
	int speed;
	DWORD oldTime;
	DWORD curTime;
	D3DXVECTOR2* ptr_pos;
	D3DXVECTOR2 Direction;
	D3DXVECTOR2 Direction0;
public:
	cEnemyMissile(int _xPos, int _yPos, D3DXVECTOR2* _pos);
	~cEnemyMissile();

	virtual void Update() override;
};