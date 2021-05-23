#pragma once

#include "cEnemy.h"
class cGuardian : public cEnemy {
public:
	cBulletAdmin* ptr_bulletAdmin;
	int randPos;
public:
	cGuardian(cBulletAdmin* _bulletAdmin);
	virtual ~cGuardian();

	virtual void Update() override;
	virtual void Render() override;
};