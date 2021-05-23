#pragma once
#include "cBullet.h"

class cEnemyBullet : public cBullet
{
private:

public:
	cEnemyBullet(int _xPos, int _yPos);
	~cEnemyBullet();

	virtual void Update() override;
};