#include "DXUT.h"
#include "cBullet.h"


cBullet::cBullet(int _xPos, int _yPos, float _angle)
{
	m_pos.x = _xPos;
	m_pos.y = _yPos;
	angle = _angle;
	heavyDMG = false;
}


cBullet::~cBullet()
{
}

void cBullet::Render()
{
	m_image->CenterRender(m_pos.x, m_pos.y, angle);
}

bool cBullet::IsOutMap()
{
	return (BulletCollider.left / 4 < 0
		|| BulletCollider.right > WINSIZEX
		|| BulletCollider.top / 4 < 0
		|| BulletCollider.bottom > WINSIZEY);
}
