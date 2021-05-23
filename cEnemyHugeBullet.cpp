#include "DXUT.h"
#include "cEnemyHugeBullet.h"

cEnemyHugeBullet::cEnemyHugeBullet(int _xPos, int _yPos)
	:cBullet(_xPos, _yPos, 90)
{
	bulletType = "Enemy";
	m_image = IMAGEMANAGER->AddImage("enemyHugeBullet", "./image/HugeBullet.png");
	speed = 100;
	oldTime = timeGetTime();
	curTime = timeGetTime();
}

cEnemyHugeBullet::~cEnemyHugeBullet()
{
}

void cEnemyHugeBullet::Update()
{
	SetRect(&BulletCollider, m_pos.x - m_image->info.Width / 4, m_pos.y - m_image->info.Height / 4, m_pos.x + m_image->info.Width / 4, m_pos.y + m_image->info.Height / 4);
	m_pos.y += speed * DXUTGetElapsedTime();
	if ((oldTime - curTime) % 1 == 0) {
		speed += 10;
	}
}