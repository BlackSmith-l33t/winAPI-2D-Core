#include "framework.h"
#include "CMonster.h"
#include "CCollider.h"

CMonster::CMonster()
{
	m_fptCenterPos = fPoint(0, 0);
	m_fVelocity = 0;
	m_fDistance = 300;
	m_bIsUpDir = true;

	SetName(L"Monster");
	SetScale(fPoint(100.f, 100.f));

	CreateCollider();
	GetCollider()->SetScale(fPoint(90.f, 90.f));
}

CMonster::~CMonster()
{

}

CMonster* CMonster::Clone()
{
	return new CMonster(*this);;
}

void CMonster::Update()
{
	fPoint pos = GetPos();

	if (m_bIsUpDir)
	{
		pos.y -= m_fVelocity * fDT;
		if (pos.y < m_fptCenterPos.y - m_fDistance)
		{
			m_bIsUpDir = false;
		}
	}
	else
	{
		pos.y += m_fVelocity * fDT;
		if (pos.y > m_fptCenterPos.y + m_fDistance)
		{
			m_bIsUpDir = true;
		}
	}

	SetPos(pos);
}

void CMonster::SetCenterPos(fPoint point)
{
	m_fptCenterPos = point;
}

fPoint CMonster::GetCenterPos()
{
	return m_fptCenterPos;
}

void CMonster::OnCollisionEnter(CCollider* pOther)
{
	if (L"Missile" == pOther->GetObj()->GetName())
	{
		DeleteObj(this);
	}
}
