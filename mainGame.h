#pragma once
class mainGame
{
private:

public:
	mainGame();//메인 게임 생성자
	~mainGame();//메인 게임 소멸자

	void Init();//선언 //매니저에서의 Init과 메인게임의 Init은 같은건가? 
	//변수의 값 초기화, 기본 셋팅
	void Release();//초기화
	//할당된 변수 제거
	void Update();//갱신
	//변경된 사항, 입력받는 사항
	void Render();//출력
	//화면에 보이는 것

	void LostDevice();  
	void ResetDevice();
};