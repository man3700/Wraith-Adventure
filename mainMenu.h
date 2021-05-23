#pragma once
class mainMenu
{
public:
	int subSelect;
	int select;
	bool IsMain;
	bool IsSub;
	texture* m_backGround[4];
	texture* m_subText[3];
public:
	mainMenu();
	~mainMenu();

	void Update();
	void Render();
};

