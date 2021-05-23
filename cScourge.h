#pragma once

#include "cEnemy.h"
class cScourge : public cEnemy {
public:
	vector<texture*>* textures0;
	D3DXVECTOR2* p_pos;
	int speed;
public:
	cScourge(cPlayer* _player);
	virtual ~cScourge();

	virtual void Update() override;
	virtual void Render() override;
};

