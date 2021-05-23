#include "DXUT.h"
#include "mainGame.h"
#include "cIngameScene.h"

mainGame::mainGame()//메인게임 생성자
{

}

mainGame::~mainGame()//메인게임 소멸자
{
	Release();//초기화
}

void mainGame::Init()//메인게임 선언
{
	SCENEMANAGER->AddScene("ingame", new cIngameScene);//씬 추가("ingame"이라는 씬으로 추가)
	SCENEMANAGER->ChangeScene("ingame");//씬 변경 ("ingame"이라는 씬으로 변경)
}

void mainGame::Release()//메인게임 초기화
{
	cImageManager::ReleaseInstance();
	cSceneManager::ReleaseInstance();
}

void mainGame::Update()//메인게임 갱신
{
	SCENEMANAGER->Update();
}

void mainGame::Render()//메인게임 랜더
{
	IMAGEMANAGER->Begin();//이미지 관리자를 실행한다

	SCENEMANAGER->Render();//씬 관리자를 렌더한다

	IMAGEMANAGER->End();//이미지 관리자를 종료한다
}

//잘 모르겠음
void mainGame::LostDevice()
{
}

void mainGame::ResetDevice()
{
}