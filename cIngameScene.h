#pragma once
#include "cScene.h"
#include <vector>

//ȭ�� ������ �� �����
class cScroolMap;//��ũ�Ѹ� Ŭ����
class cPlayer;//�÷��̾� Ŭ����
class cBulletAdmin;//�Ѿ� ������ Ŭ����
class cEnemyAdmin;//�� ������ Ŭ����
class mainMenu;

class cIngameScene : public cScene {// ���� ��ӹ޴� �ΰ��Ӿ� Ŭ����
private:
	mainMenu* m_main;
	cScroolMap* m_map;//��
	cPlayer* m_player;//�÷��̾�
	cBulletAdmin* m_bullet;
	cEnemyAdmin* m_enemy;
	texture* victory;

	bool IsEnd;
public:
	cIngameScene();//������
	virtual ~cIngameScene();//�Ҹ���

	virtual void Init() override;//����
	virtual void Release() override;//�ʱ�ȭ
	virtual void Update() override;//����
	virtual void Render() override;//����
};