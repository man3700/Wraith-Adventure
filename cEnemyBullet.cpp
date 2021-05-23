#include "DXUT.h"
#include "cEnemyBullet.h"

cEnemyBullet::cEnemyBullet(int _xPos, int _yPos)
	:cBullet(_xPos, _yPos, 90)
{
	bulletType = "Enemy";
	m_image = IMAGEMANAGER->AddImage("enemyBullet", "./image/EnemyBullet.png");
}

cEnemyBullet::~cEnemyBullet()
{
}

void cEnemyBullet::Update()
{
	SetRect(&BulletCollider, 
		m_pos.x - m_image->info.Width / 4, 
		m_pos.y - m_image->info.Height / 4, 
		m_pos.x + m_image->info.Width / 4, 
		m_pos.y + m_image->info.Height / 4);
	m_pos.y += 400 * DXUTGetElapsedTime();
}