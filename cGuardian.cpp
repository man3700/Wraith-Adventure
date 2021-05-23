#include "DXUT.h"
#include "cGuardian.h"
#include "cEnemy.h"
#include "cBullet.h"
#include "cBulletAdmin.h"

cGuardian::cGuardian(cBulletAdmin* _bulletAdmin)
	: ptr_bulletAdmin(_bulletAdmin)
{
	textures = IMAGEMANAGER->ADDVECIMAGE("guardian", "./image/guardian/(%d).png", 7);
	hp = 10;
	cnt = 0;
	randPos = rand() % 100;
}
cGuardian::~cGuardian() {

}

void cGuardian::Update() 
{
	curTime = timeGetTime();
	SetRect(&enemyCollider, _pos.x - ((*textures)[0]->info.Width) / 4, _pos.y - ((*textures)[0]->info.Height) / 4, _pos.x + ((*textures)[0]->info.Width) / 4, _pos.y + ((*textures)[0]->info.Height) / 4);

	if ((curTime - oldTime) % 10 == 0) cnt++;
	if (cnt >= 7)cnt = 1;

	if (curTime - oldTime >= 1000) {
		ptr_bulletAdmin->AddHugeBullet(_pos.x,_pos.y + 20);
		oldTime = curTime;
	}

	if (direction == 0) (_pos.x) -= 100 * DXUTGetElapsedTime();
	else (_pos.x) += 100 * DXUTGetElapsedTime();

	if (_pos.y < 60 + randPos && ((curTime - oldTime) % 1 == 0)) (_pos.y)++;

	if (_pos.x <= 0) direction = 1;//왼쪽에 충돌했을 때 방향을 오른쪽으로
	else if (_pos.x >= WINSIZEX) direction = 0;//오른쪽에 충돌했을 때 방향을 왼쪽으로
}
void cGuardian::Render() 
{
	(*textures)[cnt]->CenterRender(_pos.x, _pos.y);
}