#include "framework.h"
#include "CMonster.h"

CMonster::CMonster()
{
	SetScale(fPoint(200, 200));
	m_fVelocity = 200;
	m_fDistance = 250;
	m_bIsUpDir = true;

}

CMonster::~CMonster()
{

}

void CMonster::Update()
{
	fPoint pos = GetPos();

	if (m_bIsUpDir)
	{
		pos.y -= m_fVelocity * DT;
		if (pos.y < m_fptCenterPos.y - m_fDistance)
		{
			m_bIsUpDir = false;
		}
	}
	else
	{
		pos.y += m_fVelocity * DT;
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
