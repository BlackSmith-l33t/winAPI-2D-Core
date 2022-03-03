#pragma once
#include "CGameObject.h"
class CPlayer : public CGameObject
{
	CTexture* m_pTex;
private:
	double m_dVelocity = 500;
public:
	CPlayer();
	virtual ~CPlayer();

	virtual void Update();
	virtual void Render(HDC hDC);

	void CreateMissile();
};

