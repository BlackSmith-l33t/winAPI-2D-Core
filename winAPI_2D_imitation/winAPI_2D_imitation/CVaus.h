#pragma once
#include "CGameObject.h"

// Vaus : ���� ������ �÷��̾ �����ϴ� ��ü 
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

