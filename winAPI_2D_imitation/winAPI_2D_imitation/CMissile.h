#pragma once
#include "CGameObject.h"
class CMissile : public CGameObject
{
private:
	fVec2 m_fvDir;
	float m_fVelocity;
public:
	CMissile();
	~CMissile();
	virtual CMissile* Clone();

	virtual void Update();
	virtual void Render(HDC hDC);

	void SetDir(fVec2 vec);
	fVec2 GetDir();

	void OnCollisionEnter(CCollider* pOther);
};

