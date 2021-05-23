#pragma once
#include "cBullet.h"

class cEnemyHugeBullet : public cBullet
{
private:
	int speed;
	DWORD oldTime;
	DWORD curTime;
public:
	cEnemyHugeBullet(int _xPos, int _yPos);
	~cEnemyHugeBullet();

	virtual void Update() override;
};