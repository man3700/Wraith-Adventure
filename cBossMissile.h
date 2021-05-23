#pragma once
#include "cBullet.h"
#include "cPlayer.h"

class cBossMissile : public cBullet
{
private:
	D3DXVECTOR2 angle_pos;
	D3DXVECTOR2 Direction0;
public:
	cBossMissile(int _xPos, int _yPos, float _angle);
	~cBossMissile();

	virtual void Update() override;
};