#include "DXUT.h"
#include "cBossMissile.h"
#include "cPlayer.h"

cBossMissile::cBossMissile(int _xPos, int _yPos, float _angle)
	: cBullet(_xPos, _yPos, angle)
{
	bulletType = "Boss";
	m_image = IMAGEMANAGER->AddImage("bossMissile", "./image/bossMissile.png");
	angle_pos.x = m_pos.x + (cos((D3DXToRadian(_angle))));
	angle_pos.y = m_pos.y + (sin((D3DXToRadian(_angle))));
	D3DXVec2Normalize(&Direction0, &(angle_pos - m_pos));
	angle = D3DXToDegree(atan2f(Direction0.y, Direction0.x));
}

cBossMissile::~cBossMissile() {

}

void cBossMissile::Update() {
	SetRect(&BulletCollider, m_pos.x - m_image->info.Width / 4, m_pos.y - m_image->info.Height / 4, m_pos.x + m_image->info.Width / 4, m_pos.y + m_image->info.Height / 4);
	m_pos += Direction0 * 125 * DXUTGetElapsedTime();
}