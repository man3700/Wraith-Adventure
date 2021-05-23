#include "DXUT.h"
#include "cScourge.h"
#include "cEnemy.h"
#include "cEnemyBullet.h"
#include "cPlayer.h"

cScourge::cScourge(cPlayer* _player)
	:p_pos(&(_player->player_pos))
{
	textures = IMAGEMANAGER->ADDVECIMAGE("scourge right", "./image/scourge/(%d).right.png", 5);
	textures0 = IMAGEMANAGER->ADDVECIMAGE("scourge left", "./image/scourge/(%d).left.png", 5);
	cnt = 0;
	hp = 1;
	speed = 0;
}

cScourge::~cScourge() {

}

void cScourge::Update()
{
	curTime = timeGetTime();
	SetRect(&enemyCollider, _pos.x - ((*textures)[0]->info.Width) / 4, _pos.y - ((*textures)[0]->info.Height) / 4, _pos.x + ((*textures)[0]->info.Width) / 4, _pos.y + ((*textures)[0]->info.Height) / 4);
	if ((curTime - oldTime) % 15 == 0) {
		cnt++;
		oldTime = curTime;
	}
	if (cnt >= 5) cnt = 0;

	if ((p_pos->y) > (_pos.y)) {
		if ((curTime - oldTime) % 1 == 0) {
			if ((p_pos->x) > (_pos.x)) {
				direction = 0;
				speed++;
				if (speed > 15) speed = 15;
			}
			else {
				direction = 1;
				speed--;
				if (speed < -15) speed = (-15);
			}
		}
	}
	if ((curTime - oldTime) % 1 == 0) {
		(_pos.x) += speed / 5;
		(_pos.y) += 4;
	}
}

void cScourge::Render()
{
	if (direction == 0) (*textures)[cnt]->CenterRender(_pos.x, _pos.y);
	else (*textures0)[cnt]->CenterRender(_pos.x, _pos.y);
}
