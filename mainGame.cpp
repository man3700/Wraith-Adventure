#include "DXUT.h"
#include "mainGame.h"
#include "cIngameScene.h"

mainGame::mainGame()//���ΰ��� ������
{

}

mainGame::~mainGame()//���ΰ��� �Ҹ���
{
	Release();//�ʱ�ȭ
}

void mainGame::Init()//���ΰ��� ����
{
	SCENEMANAGER->AddScene("ingame", new cIngameScene);//�� �߰�("ingame"�̶�� ������ �߰�)
	SCENEMANAGER->ChangeScene("ingame");//�� ���� ("ingame"�̶�� ������ ����)
}

void mainGame::Release()//���ΰ��� �ʱ�ȭ
{
	cImageManager::ReleaseInstance();
	cSceneManager::ReleaseInstance();
}

void mainGame::Update()//���ΰ��� ����
{
	SCENEMANAGER->Update();
}

void mainGame::Render()//���ΰ��� ����
{
	IMAGEMANAGER->Begin();//�̹��� �����ڸ� �����Ѵ�

	SCENEMANAGER->Render();//�� �����ڸ� �����Ѵ�

	IMAGEMANAGER->End();//�̹��� �����ڸ� �����Ѵ�
}

//�� �𸣰���
void mainGame::LostDevice()
{
}

void mainGame::ResetDevice()
{
}