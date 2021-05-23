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

cIngameScene::cIngameScene()//������
{
	victory = IMAGEMANAGER->AddImage("victory","./image/victory.png");
	IsEnd = false;
}

cIngameScene::~cIngameScene()//�Ҹ���
{
}

void cIngameScene::Init()//����
{//Ŭ���� ����
	m_main = new mainMenu();
	m_map = new cScroolMap();//��(��ũ�Ѹ�)
	m_bullet = new cBulletAdmin();//�Ѿ�(�Ѿ� ������)
	m_player = new cPlayer(m_bullet);//�÷��̾�(�÷��̾�)
	m_enemy = new cEnemyAdmin(m_player,m_bullet,m_map);//��(�� ������)
}

void cIngameScene::Release()
{
	SAFE_DELETE(m_main);
	SAFE_DELETE(m_map);//���� �����Ѵ�
	SAFE_DELETE(m_player);//�÷��̾ �����Ѵ�
	SAFE_DELETE(m_enemy);
	PlaySound(NULL, 0, 0);
}

void cIngameScene::Update()//�����Ѵ�
{
	if (m_main->IsMain == true) {
		m_main->Update();
	}
	else {
		m_map->Update(50);//���� �̵��ӵ��� �����Ѵ�
		m_player->Update();//�÷��̾ �����Ѵ�
		m_bullet->Update();//�Ѿ��� �����Ѵ�
		m_enemy->Update();
	}
}

void cIngameScene::Render()//����
{
	if (m_main->IsMain == true) {
		m_main->Render();
	}else {
		m_map->Render();//���� �����Ѵ�
		m_bullet->Render();//�Ѿ��� �����Ѵ�
		m_enemy->Render();
		m_player->Render();//�÷��̾ �����Ѵ�
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
		SCENEMANAGER->ChangeScene("ingame");//�� ���� ("ingame"�̶�� ������ ����)
		SAFE_DELETE(victory);
		if(IsEnd == true)IsEnd == false;
		m_enemy->MakeOnceBoss = false;
	}
}