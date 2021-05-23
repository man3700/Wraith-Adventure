#pragma once

#include "cEnemy.h"
class cMutalisk : public cEnemy {
public:
	vector<texture*>* textures0;
	D3DXVECTOR2* ptr_pos;
	cBulletAdmin* ptr_bulletAdmin;
	bool direction0;
	bool hitBottom;
public:
	cMutalisk(cBulletAdmin* _bulletAdmin, cPlayer* _player);
	virtual ~cMutalisk();

	virtual void Update() override;
	virtual void Render() override;
};