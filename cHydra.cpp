#include "DXUT.h"
#include "cHydra.h"
#include "cEnemy.h"
#include "cEnemyAdmin.h"
#include "cBulletAdmin.h"

cHydra::cHydra(cBulletAdmin* _bulletAdmin)
	: ptr_bulletAdmin(_bulletAdmin)
{
	textures = IMAGEMANAGER->ADDVECIMAGE("hydra", "./image/hydra/(%d).png", 7);
	cnt = 0;
	hp = 3;
}

cHydra::~cHydra() {

}

void cHydra::Update()
{
	SetRect(&enemyCollider, _pos.x - ((*textures)[0]->info.Width) / 4, _pos.y - ((*textures)[0]->info.Height) / 4, _pos.x + ((*textures)[0]->info.Width) / 4,_pos.y + ((*textures)[0]->info.Height) / 4);
	curTime = timeGetTime();

	if ((curTime - oldTime) % 10  == 0) cnt++;
	if (cnt >= 7)cnt = 0;

	if (curTime - oldTime >= 800) {
		ptr_bulletAdmin->AddEnemyBullet(_pos.x,_pos.y + 20);
		oldTime = curTime;
	}

	if (direction == 0) (_pos.x) -= 200 * DXUTGetElapsedTime();
	else (_pos.x) += 200 * DXUTGetElapsedTime();

	if((curTime - oldTime) % 1 == 0) (_pos.y)++;

	if (_pos.x <= 0) direction = 1;//왼쪽에 충돌했을 때 방향을 오른쪽으로
	else if (_pos.x >= WINSIZEX) direction = 0;//오른쪽에 충돌했을 때 방향을 왼쪽으로
}

void cHydra::Render()
{
	(*textures)[cnt]->CenterRender(_pos.x,_pos.y);
}
