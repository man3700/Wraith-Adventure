#pragma once
class cBullet abstract
{
public:
	texture* m_image;
	D3DXVECTOR2 m_pos;
	RECT BulletCollider;
	string bulletType;

	bool heavyDMG;
	double m_size;
	float angle;
public:
	cBullet(int xPos, int yPos, float _angle);
	virtual ~cBullet();

	virtual void Update() PURE;
	void Render();
	D3DXVECTOR2 GetPos() { return m_pos; }
	bool IsOutMap();
};