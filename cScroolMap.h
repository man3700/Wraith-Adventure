#pragma once
class cScroolMap
{
public:
	int sceneNum;
	float m_scrool;
	texture* m_backGround[2];
public:
	cScroolMap();
	~cScroolMap();

	void Update(float speed);
	void Render();

	float GetScrool() { return m_scrool; }
};

