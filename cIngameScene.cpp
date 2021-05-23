#include "DXUT.h"
#include "cIngameScene.h"

#include "cScroolMap.h"
#include "cBulletAdmin.h"
#include "cPlayer.h"
#include "cEnemyAdmin.h"
//#include "cHydra.h"
//#include "cMutalisk.h"
//#include "cGuardian.h"
//#include "cScourge.h"
#include "cBulletAdmin.h"
#include "cEnemyAdmin.h"
#include "mainMenu.h"

cIngameScene::cIngameScene()//생성자
{
	victory = IMAGEMANAGER->AddImage("victory","./image/victory.png");
	IsEnd = false;
}

cIngameScene::~cIngameScene()//소멸자
{
}

void cIngameScene::Init()//선언
{//클래스 생성
	m_main = new mainMenu();
	m_map = new cScroolMap();//맵(스크롤맵)
	m_bullet = new cBulletAdmin();//총알(총알 관리자)
	m_player = new cPlayer(m_bullet);//플레이어(플레이어)
	m_enemy = new cEnemyAdmin(m_player,m_bullet,m_map);//적(적 관리자)
}

void cIngameScene::Release()
{
	SAFE_DELETE(m_main);
	SAFE_DELETE(m_map);//맵을 삭제한다
	SAFE_DELETE(m_player);//플레이어를 삭제한다
	SAFE_DELETE(m_enemy);
	PlaySound(NULL, 0, 0);
}

void cIngameScene::Update()//갱신한다
{
	if (m_main->IsMain == true) {
		m_main->Update();
	}
	else {
		m_map->Update(50);//맵의 이동속도를 변경한다
		m_player->Update();//플레이어를 갱신한다
		m_bullet->Update();//총알을 갱신한다
		m_enemy->Update();
	}
}

void cIngameScene::Render()//렌더
{
	if (m_main->IsMain == true) {
		m_main->Render();
	}else {
		m_map->Render();//맵을 렌더한다
		m_bullet->Render();//총알을 렌더한다
		m_enemy->Render();
		m_player->Render();//플레이어를 렌더한다
		if (m_enemy->IsBoss == true) {
			if (m_enemy->m_boss->hp <= 0) {
				SAFE_DELETE(m_enemy->m_boss);
				m_enemy->IsBoss = false;
				m_bullet->Reset();
				IsEnd = true;
				PlaySound(NULL, 0, 0);
			}
		}
	}
	if (IsEnd == true)victory->CenterRender(WINSIZEX / 2, WINSIZEY / 2);
	if (GetAsyncKeyState('R') & 0x8000)
	{
		SCENEMANAGER->ChangeScene("ingame");//씬 변경 ("ingame"이라는 씬으로 변경)
		SAFE_DELETE(victory);
		if(IsEnd == true)IsEnd == false;
		m_enemy->MakeOnceBoss = false;
	}
}