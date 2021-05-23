#include "DXUT.h"
#include "cImageManager.h"

void texture::Render(float x, float y, float size, float rot, D3DCOLOR color){
	IMAGEMANAGER->Render(this, x, y, size, rot, color);
}

void texture::Render(float x, float y, float rot){
	IMAGEMANAGER->Render(this, x, y, rot);
}

void texture::CenterRender(float x, float y, float size, float rot, D3DCOLOR color){
	IMAGEMANAGER->CenterRender(this, x, y, size, rot, color);
}

void texture::CenterRender(float x, float y, float rot){
	IMAGEMANAGER->CenterRender(this, x, y, rot);
}

cImageManager::cImageManager():m_sprite(nullptr){
	Init();
}


cImageManager::~cImageManager(){
	Release();
}

//불러올 이미지를 부를 이름과 경로
texture* cImageManager::AddImage(const string& key, const string& path){
	auto find = m_images.find(key);//이미 있는 이름을 다시 쓰려고 하는게 아닌지 확인해본다
	if (find == m_images.end()){
		LPDIRECT3DTEXTURE9 texturePtr;
		D3DXIMAGE_INFO info;

		if (D3DXCreateTextureFromFileExA(g_device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, 0, &info, nullptr, &texturePtr) == S_OK){
			texture* text = new texture(texturePtr, info);
			m_images.insert(make_pair(key, text));
			return text;
		}
		#pragma region 로딩실패
		DEBUG_LOG("ERROR! 이미지 로딩에 실패했습니다. 파일경로를 다시 확인해주세요");
		DEBUG_LOG("\tkey :" << key.c_str() << "\t path : " << path.c_str());
		#pragma endregion
		return nullptr;
	}
	return find->second;
}

texture* cImageManager::FindImage(const string& key){
	auto find = m_images.find(key);//이름으로 이미지를 찾아본다
	if (find == m_images.end()) return nullptr;//없으면 nullptr을 뱉는다
	return find->second;//있으면 그걸 뱉는다
}

vector<texture*>* cImageManager::ADDVECIMAGE(const string& key, const string& path, int max){
	auto find = vecImages.find(key);
	if (find != vecImages.end())
		return find->second;

	vector<texture*>* vec = new vector<texture*>();

	for (int i = 1; i <= max; i++){
		LPDIRECT3DTEXTURE9 lpTexture;
		D3DXIMAGE_INFO info;

		char ch[256];
		wsprintfA(ch, path.c_str(), i);

		if (D3DXCreateTextureFromFileExA(g_device, ch, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0,
			D3DFMT_A8R8G8B8, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, NULL, &info, nullptr, &lpTexture) == S_OK){
			texture* text = new texture(lpTexture, info);
			vec->push_back(text);
		}
		else{
			SAFE_RELEASE(lpTexture);
		}
	}
	if (vec->empty()){
		SAFE_DELETE(vec);
		return nullptr;
	}
	vecImages[key] = vec;
	return vec;
}

vector<texture*>* cImageManager::FINDVECIMAGE(const string& key, int max){
	return vecImages[key];
}

void cImageManager::Init(){
	D3DXCreateSprite(g_device, &m_sprite);
}

void cImageManager::Release(){
	for (auto iter : m_images){
		iter.second->texturePtr->Release();
		SAFE_DELETE(iter.second);
	}
	m_images.clear();

	m_sprite->Release();
}

void cImageManager::Begin(){
	m_sprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void cImageManager::End(){
	m_sprite->End();
}

void cImageManager::Render(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color){
	if (texturePtr){
		D3DXMATRIXA16 mat;

		D3DXMatrixAffineTransformation2D(&mat, size, nullptr, D3DXToRadian(rot), &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, color);
	}
}

void cImageManager::Render(texture* texturePtr, float x, float y, float rot){
	if (texturePtr){
		D3DXMATRIXA16 mat;

		D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, D3DXToRadian(rot), &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, nullptr, nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}
}

void cImageManager::CenterRender(texture* texturePtr, float x, float y, float size, float rot, D3DCOLOR color){
	Render(texturePtr, x - texturePtr->info.Width / 2, y - texturePtr->info.Height / 2, size, rot, color);
}

void cImageManager::CenterRender(texture* texturePtr, float x, float y, float rot){
	if (texturePtr) {
		D3DXMATRIXA16 mat;

		D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, D3DXToRadian(rot), &D3DXVECTOR2(x, y));
		m_sprite->SetTransform(&mat);
		m_sprite->Draw(texturePtr->texturePtr, nullptr, &D3DXVECTOR3(texturePtr->info.Width / 2, texturePtr->info.Height / 2, 0), nullptr, D3DCOLOR_XRGB(255, 255, 255));
	}


}

void cImageManager::LostDevice(){
	m_sprite->OnLostDevice();
}

void cImageManager::ResetDevice(){
	m_sprite->OnResetDevice();
}
