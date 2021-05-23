#pragma once
#include "cEnemy.h"
class cHydra : public cEnemy{
public:
	cBulletAdmin* ptr_bulletAdmin;
public:
	cHydra(cBulletAdmin* _bulletAdmin);
	virtual ~cHydra();

	virtual void Update() override;
	virtual void Render() override;
};

