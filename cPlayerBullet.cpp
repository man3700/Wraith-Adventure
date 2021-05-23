#include "DXUT.h"
#include "cPlayerBullet.h"

cPlayerBullet::cPlayerBullet(int _xPos, int _yPos, float _angle)
	:cBullet(_xPos, _yPos, 90)
{
	bulletType = "Player";
	m_image = IMAGEMANAGER->AddImage("playerBullet", "./image/playerBullet.png");
	angle_pos.x = (cos(D3DXToRadian(_angle)));
	angle_pos.y = (sin(D3DXToRadian(_angle)));
	D3DXVec2Normalize(&Direction0, &(angle_pos));
	angle = D3DXToDegree(atan2f(Direction0.y, Direction0.x));
}

cPlayerBullet::~cPlayerBullet()
{

}

void cPlayerBullet::Update()
{
	SetRect(&BulletCollider, m_pos.x - m_image->info.Width / 4, m_pos.y - m_image->info.Height / 4, m_pos.x + m_image->info.Width / 4, m_pos.y + m_image->info.Height / 4);

	m_pos +=  Direction0 * 500 * DXUTGetElapsedTime();
}