#include "DXUT.h"
#include "cScroolMap.h"


cScroolMap::cScroolMap()
	:m_scrool(0)
{
	sceneNum = 0;
	m_backGround[0] = IMAGEMANAGER->AddImage("mapBackGround", "./image/mapBackGround.png");
	m_backGround[1] = IMAGEMANAGER->AddImage("mapBackGroundBoss", "./image/bossMap.png");

}

cScroolMap::~cScroolMap()
{
}

void cScroolMap::Update(float speed)
{
	if (sceneNum == 0) m_scrool += speed * DXUTGetElapsedTime();
	else if(sceneNum == 1) m_scrool = 0;
}

void cScroolMap::Render()
{
	//반복되는 백그라운드 이미지를 예시로 사용할것임
	float renderPos = (int)m_scrool % m_backGround[sceneNum]->info.Height;
	 m_backGround[sceneNum]->CenterRender(768 / 2, 600 / 2 + renderPos - m_backGround[sceneNum]->info.Height);
	m_backGround[sceneNum]->CenterRender(768 / 2, 600 / 2 + renderPos);
}
