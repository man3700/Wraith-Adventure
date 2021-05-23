#pragma once
#include "singleton.h"

class cScene;
class cSceneManager : public singleton<cSceneManager>{
private:
	cScene* m_nowScene;
	cScene* m_nextScene;
	map<string, cScene*> m_scenes;
	void Release();
public:
	cSceneManager();
	~cSceneManager();

	cScene* AddScene(const string& key, cScene* scenePtr);
	cScene* ChangeScene(const string& key);

	void Update();
	void Render();
};

#define SCENEMANAGER cSceneManager::GetInstance()