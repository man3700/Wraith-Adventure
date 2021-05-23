#include "DXUT.h"
#include "cPlayer.h"
#include "cBulletAdmin.h"
#include "cBullet.h"
#include "cEnemyAdmin.h"
#include "cIngameScene.h"

cPlayer::cPlayer(cBulletAdmin *_bulletAdmin) 
	: player_pos(WINSIZEX / 2, 450), ptr_bulletAdmin(_bulletAdmin)
{
	shootDelay = 15;
	skillDelay = 10;
	hitDelay = 50;
	playerHP = 20;
	shiftMove = 300;
	playOnce = false;

	playerImage[0] = IMAGEMANAGER->AddImage("player", "./image/player.png");
	playerImage[1] = IMAGEMANAGER->AddImage("damaged_player", "./image/damaged_player.png");
	skillImage[0] = IMAGEMANAGER->AddImage("skillAble","./image/skillAble.png");
	skillImage[1] = IMAGEMANAGER->AddImage("skillEnable", "./image/skillEnable.png");
	gameover = IMAGEMANAGER->AddImage("gameover", "./image/gameover.png");
	heart[0] = IMAGEMANAGER->AddImage("heart", "./image/heart.png");
	heart[1] = IMAGEMANAGER->AddImage("empty_heart", "./image/empty_heart.png");

	SetRect(&playerCollider,
		player_pos.x - (playerImage[0]->info.Width) / 4,
		player_pos.y - (playerImage[0]->info.Height) / 4,
		player_pos.x + (playerImage[0]->info.Width) / 4,
		player_pos.y + (playerImage[0]->info.Height) / 4
	);

	curTime = timeGetTime();
	oldTime = timeGetTime();
}


cPlayer::~cPlayer()
{
}

void cPlayer::Update()
{
	curTime = timeGetTime();
	SetRect(&playerCollider,
		player_pos.x - (playerImage[0]->info.Width) / 4,
		player_pos.y - (playerImage[0]->info.Height) / 4,
		player_pos.x + (playerImage[0]->info.Width) / 4,
		player_pos.y + (playerImage[0]->info.Height) / 4
	);
	
	if (playerHP > 0) {
		shootDelay++;
		if (curTime - oldTime >= 1000) { oldTime = timeGetTime(); skillDelay++; }
		hitDelay++;
		if (GetAsyncKeyState(VK_LSHIFT) & 0x8000 && playerCollider.left > 0) shiftMove = 150;
		else shiftMove = 300;
		if (GetAsyncKeyState(VK_LEFT) & 0x8000 && playerCollider.left > 0)
			player_pos.x -= shiftMove * DXUTGetElapsedTime();
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && playerCollider.right < WINSIZEX)
			player_pos.x += shiftMove * DXUTGetElapsedTime();
		if (GetAsyncKeyState(VK_UP) & 0x8000 && playerCollider.top > 0)
			player_pos.y -= shiftMove * DXUTGetElapsedTime();
		if (GetAsyncKeyState(VK_DOWN) & 0x8000 && playerCollider.bottom < WINSIZEY)
			player_pos.y += shiftMove * DXUTGetElapsedTime();
		if (GetAsyncKeyState(VK_SPACE) & 0x8000 && shootDelay >= 15)
		{
			ptr_bulletAdmin->AddPlayerBullet((player_pos.x) - (playerImage[0]->info.Width) / 3, player_pos.y, 270);
			ptr_bulletAdmin->AddPlayerBullet((player_pos.x), player_pos.y - 10, 270);
			ptr_bulletAdmin->AddPlayerBullet((player_pos.x) + (playerImage[0]->info.Width) / 3, player_pos.y, 270);
			shootDelay = 0;
		}
		if (GetAsyncKeyState(VK_CONTROL) & 0x8000 && skillDelay >= 10)
		{
			for (float angle = 0; angle < 360; angle += 10) {
				ptr_bulletAdmin->AddPlayerBullet(player_pos.x, player_pos.y, angle);
			}
			for (auto iter : ptr_bulletAdmin->m_enemyBullet)
				SAFE_DELETE(iter);
			ptr_bulletAdmin->m_enemyBullet.clear();
			skillDelay = 0;
		}
	}
	else {
		if (playOnce == false) {
			PlaySound(NULL, 0, 0);
			PlaySound(TEXT("./bgm/lol_u_died.wav"), NULL, SND_ASYNC);
			playOnce = true;
		}
		if (GetAsyncKeyState('R') & 0x8000)
		{
			SCENEMANAGER->ChangeScene("ingame");//씬 변경 ("ingame"이라는 씬으로 변경)
		}
	}

	CollisionBullet();
}

void cPlayer::Render()
{
	if (hitDelay >= 50) playerImage[0]->CenterRender((player_pos.x), player_pos.y);
	else playerImage[1]->CenterRender(player_pos.x, player_pos.y);
	if (skillDelay >= 10) skillImage[0]->CenterRender(40,40);
	else skillImage[1]->CenterRender(40, 40);
	if (playerHP <= 0) {
		gameover->CenterRender(WINSIZEX/2,WINSIZEY/2);
	}
	for (int i = 0; i < 20; i++) {
		if (i < playerHP) heart[0]->CenterRender(40, 80 + i * 20);
		else heart[1]->CenterRender(40, 80 + i * 20);
	}
}

bool cPlayer::IsCollisionEnemyBullet(cBullet* enemyB)
{
	RECT re;
	return IntersectRect(&re, &playerCollider, &enemyB->BulletCollider);
}

void cPlayer::CollisionBullet()
{
	if (hitDelay >= 50) {
		for (auto iter = ptr_bulletAdmin->m_enemyBullet.begin(); iter != ptr_bulletAdmin->m_enemyBullet.end();)
		{
			if (IsCollisionEnemyBullet(*iter))
			{
				if ((*iter)->heavyDMG == true) playerHP -= 3;
				else playerHP--;
				SAFE_DELETE(*iter);
				iter = ptr_bulletAdmin->m_enemyBullet.erase(iter);
				hitDelay = 0;
			}
			else iter++; 
		}
	}
}
