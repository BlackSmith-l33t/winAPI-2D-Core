#pragma once
#include "CGameObject.h"
class CBall : public CGameObject
{
private:
	float m_fVelocity;
	float m_fDistance;
	bool  m_bIsUpDir;

public:
	CBall();
	virtual ~CBall();

	virtual void Update();
	virtual void Render(HDC hDC);
};

