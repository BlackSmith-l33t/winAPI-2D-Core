#pragma once
#include "CGameObject.h"

class CTexture;

class CPlayer : public CGameObject
{
private:
	CTexture* m_pTex;
	float m_fVelocity = 500;
	
	void CreateMissile();
public:
	CPlayer();
	virtual ~CPlayer();
	virtual CPlayer* Clone();

	virtual void Update();
	virtual void Render(HDC hDC);
};

