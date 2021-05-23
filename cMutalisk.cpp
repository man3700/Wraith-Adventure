#include "DXUT.h"
#include "cMutalisk.h"
#include "cEnemy.h"
#include "cBulletAdmin.h"
#include "cPlayer.h"

cMutalisk::cMutalisk(cBulletAdmin* _bulletAdmin, cPlayer* _player)
	:ptr_bulletAdmin(_bulletAdmin), ptr_pos(&(_player->player_pos))
{
	textures = IMAGEMANAGER->ADDVECIMAGE("mutalisk right", "./image/mutalisk/(%d).right.png", 5);
	textures0 = IMAGEMANAGER->ADDVECIMAGE("mutalisk left", "./image/mutalisk/(%d).left.png", 5);
	cnt = 0;
	hp = 10;
	direction0 = 1;
	hitBottom = 0;
}

cMutalisk::~cMutalisk() {

}

void cMutalisk::Update() {
	curTime = timeGetTime(); 
	SetRect(&enemyCollider, _pos.x - ((*textures)[0]->info.Width) / 4, _pos.y - ((*textures)[0]->info.Height) / 4, _pos.x + ((*textures)[0]->info.Width) / 4, _pos.y + ((*textures)[0]->info.Height) / 4);

	if ((curTime - oldTime) % 5 == 0) cnt++;
	if (cnt >= 5)cnt = 0;

	if (direction == 0) (_pos.x) -= 300 * DXUTGetElapsedTime();
	else (_pos.x) += 200 * DXUTGetElapsedTime();

	if (direction0 == 0) (_pos.y) -= 300 * DXUTGetElapsedTime();
	else (_pos.y) += 200 * DXUTGetElapsedTime();

	if (_pos.x <= 0) direction = 1;//왼쪽에 충돌했을 때 방향을 오른쪽으로
	else if (_pos.x >= WINSIZEX) direction = 0;//오른쪽에 충돌했을 때 방향을 왼쪽으로
	
	if (enemyCollider.top <= 5 && hitBottom == 1) direction0 = 1;
	else if (enemyCollider.bottom >= WINSIZEY - 5) {
		direction0 = 0;
		hitBottom = 1;
	}

	if (curTime - oldTime >= 1200) {
		ptr_bulletAdmin->AddEnemyMissile(_pos.x, _pos.y, ptr_pos);
		oldTime = curTime;
	}
}
void cMutalisk::Render() {
	if (direction == 1) (*textures)[cnt]->CenterRender(_pos.x, _pos.y + 20);
	else (*textures0)[cnt]->CenterRender(_pos.x, _pos.y);
}