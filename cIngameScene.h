#pragma once
#include "cScene.h"
#include <vector>

//화면 렌더의 총 담당자
class cScroolMap;//스크롤맵 클래스
class cPlayer;//플레이어 클래스
class cBulletAdmin;//총알 관리자 클래스
class cEnemyAdmin;//적 관리자 클래스
class mainMenu;

class cIngameScene : public cScene {// 씬을 상속받는 인게임씬 클래스
private:
	mainMenu* m_main;
	cScroolMap* m_map;//맵
	cPlayer* m_player;//플레이어
	cBulletAdmin* m_bullet;
	cEnemyAdmin* m_enemy;
	texture* victory;

	bool IsEnd;
public:
	cIngameScene();//생성자
	virtual ~cIngameScene();//소멸자

	virtual void Init() override;//선언
	virtual void Release() override;//초기화
	virtual void Update() override;//갱신
	virtual void Render() override;//렌더
};