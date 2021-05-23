#include "DXUT.h"
#include "mainMenu.h"


mainMenu::mainMenu()
{
	PlaySound(TEXT("./bgm/main.wav"), NULL, SND_ASYNC);
	select = 0;
	IsMain = true;
	IsSub = false;
	m_backGround[0] = IMAGEMANAGER->AddImage("mainMenu0", "./image/Wraith Adventure 1.png");
	m_backGround[1] = IMAGEMANAGER->AddImage("mainMenu1", "./image/Wraith Adventure 2.png");
	m_backGround[2] = IMAGEMANAGER->AddImage("mainMenu2", "./image/Wraith Adventure 3.png");
	m_backGround[3] = IMAGEMANAGER->AddImage("mainMenu3", "./image/Wraith Adventure 4.png");
	m_subText[0] = IMAGEMANAGER->AddImage("sub0", "./image/subText 1.png");
	m_subText[1] = IMAGEMANAGER->AddImage("sub2", "./image/subText 2.png");
	m_subText[2] = IMAGEMANAGER->AddImage("sub3", "./image/subText 3.png");
}

mainMenu::~mainMenu()
{
	PlaySound(NULL,0,0);
}

void mainMenu::Update()
{
	if (!IsSub) {
		if ((GetAsyncKeyState(VK_LEFT) & 0x0001 || GetAsyncKeyState(VK_UP) & 0x0001)) {
			select--;
			if (select < 0) select = 3;
		}
		if ((GetAsyncKeyState(VK_RIGHT) & 0x0001 || GetAsyncKeyState(VK_DOWN) & 0x0001)) {
			select++;
			if (select > 3) select = 0;
		}
		if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
			switch (select) {
			case 0:
				IsMain = false;
				PlaySound(NULL, 0, 0);
				PlaySound(TEXT("./bgm/inGame 0.wav"), NULL, SND_ASYNC);
				break;
			case 1:
				subSelect = 0;
				IsSub = true;
				break;
			case 2:
				subSelect = 1;
				IsSub = true;
				break;
			case 3:
				subSelect = 2;
				IsSub = true;
				break;
			}
		}
	}
	else {
		if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
			IsSub = false;
		}
	}
}

void mainMenu::Render()
{
	m_backGround[select]->CenterRender(WINSIZEX / 2, WINSIZEY / 2);
	if (IsSub) {
		m_subText[subSelect]->CenterRender(WINSIZEX / 2, WINSIZEY / 2);
	}
}
