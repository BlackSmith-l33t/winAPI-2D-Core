#pragma once
#include "CGameObject.h"

// Vaus : 게임 내에서 플레이어가 조종하는 객체 
class CVaus :  public CGameObject
{
private:
	double m_dVausSpeed = 500;

public:
	CVaus();
	virtual ~CVaus();

	virtual void Update();
	virtual void Render(HDC hDC);
};

