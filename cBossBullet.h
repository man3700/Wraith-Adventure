#pragma once
#include "cBullet.h"

class cBossBullet : public cBullet
{
public:
	D3DXVECTOR2 angle_pos;
	D3DXVECTOR2 Direction0;
public:
	cBossBullet(int _xPos, int _yPos, float angle);
	~cBossBullet();

	virtual void Update() override;
};
