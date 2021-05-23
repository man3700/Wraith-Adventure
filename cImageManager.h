#pragma once
#include "singleton.h"

struct texture{
	LPDIRECT3DTEXTURE9 texturePtr;
	D3DXIMAGE_INFO info;

	texture(LPDIRECT3DTEXTURE9 texturePtr, D3DXIMAGE_INFO info)
		:texturePtr(texturePtr), info(info){

	}

	void Render(float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(float x, float y, float rot = 0);

	void CenterRender(float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(float x, float y, float rot = 0);
};

class cImageManager : public singleton <cImageManager>
{
private:
	LPD3DXSPRITE m_sprite;
	map<string, texture*> m_images;
	map<string, vector<texture*>*> vecImages;

	void Init();
	void Release();
public:
	cImageManager();
	virtual ~cImageManager();

	texture* AddImage(const string& key, const string& path);
	texture* FindImage(const string& key);
	vector<texture*>* ADDVECIMAGE(const string& key, const string& path, int max);
	vector<texture*>* FINDVECIMAGE(const string& key, int max);

	void Begin();
	void End();

	void Render(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void Render(texture* texturePtr, float x, float y, float rot = 0);

	void CenterRender(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255));
	void CenterRender(texture* texturePtr, float x, float y, float rot = 0);

	void LostDevice();
	void ResetDevice();
};

#define IMAGEMANAGER cImageManager::GetInstance()