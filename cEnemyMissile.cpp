#include "DXUT.h"
#include "cEnemyMissile.h"
#include "cPlayer.h"

cEnemyMissile::cEnemyMissile(int _xPos, int _yPos, D3DXVECTOR2* _pos)
	: cBullet(_xPos, _yPos, 90), ptr_pos(_pos)
{
	bulletType = "Enemy";
	m_image = IMAGEMANAGER->AddImage("enemyMissile", "./image/EnemyMissile.png");
	oldTime = curTime = timeGetTime();

	D3DXVec2Normalize(&Direction0, &(*(ptr_pos) - m_pos));
	angle = D3DXToDegree(atan2f(Direction0.y, Direction0.x));
}

cEnemyMissile::~cEnemyMissile() {

}

void cEnemyMissile::Update() {
	SetRect(&BulletCollider, m_pos.x - m_image->info.Width / 4, m_pos.y - m_image->info.Height / 4, m_pos.x + m_image->info.Width / 4,m_pos.y + m_image->info.Height / 4);
	m_pos += Direction0 * 300 * DXUTGetElapsedTime();
}