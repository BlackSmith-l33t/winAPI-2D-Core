#pragma once
#include "CGameObject.h"
class CMonster : public CGameObject
{
private:
	fPoint m_fptCenterPos;
	float m_fVelocity;
	float m_fDistance;
	bool  m_bIsUpDir;

public:
	CMonster();
	virtual ~CMonster();
	virtual CMonster* Clone();

	virtual void Update();

	void SetCenterPos(fPoint point);
	fPoint GetCenterPos();

	void OnCollisionEnter(CCollider* pOther);
};

