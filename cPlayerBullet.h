#pragma once
#include "cBullet.h"

class cPlayerBullet : public cBullet
{
private:
	D3DXVECTOR2 angle_pos;
	D3DXVECTOR2 Direction0;
public:
	cPlayerBullet(int _xPos, int _yPos, float angle);
	~cPlayerBullet();

	virtual void Update() override;
};

