#include "DXUT.h"
#include "cBossArrow.h"
#include "cPlayer.h"

cBossArrow::cBossArrow(int _xPos, int _yPos, D3DXVECTOR2* _pos)
	: cBullet(_xPos, _yPos, 90), ptr_pos(_pos)
{
	bulletType = "Boss";
	m_image = IMAGEMANAGER->AddImage("bossArrow", "./image/bossArrow.png");
	oldTime = curTime = timeGetTime();

	D3DXVec2Normalize(&Direction0, &(*(ptr_pos)-m_pos));
	angle = D3DXToDegree(atan2f(Direction0.y, Direction0.x));
}

cBossArrow::~cBossArrow() {

}

void cBossArrow::Update() {
	SetRect(&BulletCollider, m_pos.x - m_image->info.Width / 4, m_pos.y - m_image->info.Height / 4, m_pos.x + m_image->info.Width / 4, m_pos.y + m_image->info.Height / 4);

	m_pos += Direction0 * 100 * DXUTGetElapsedTime();
}