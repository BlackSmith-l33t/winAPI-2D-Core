#include "framework.h"
#include "CGameObject.h"
#include "CCollider.h"

CGameObject::CGameObject()
{
	m_pCollider = nullptr;
}

CGameObject::~CGameObject()
{
	if (nullptr != m_pCollider)
	{
		delete m_pCollider;
	}
}

void CGameObject::SetPos(fPoint pos)
{
	m_fptPos = pos;
}

void CGameObject::SetScale(fPoint scale)
{
	m_fptScale = scale;
}

fPoint CGameObject::GetPos()
{
	return m_fptPos;
}

fPoint CGameObject::GetScale()
{
	return m_fptScale;
}

void CGameObject::FinalUpdate()
{
	if (nullptr != m_pCollider)
	{
		m_pCollider->FinalUpdate();
	}
}

void CGameObject::Render(HDC hDC)
{
	// Test용 (지워야 할 것)
	Rectangle(hDC,
		(int)m_fptPos.x - m_fptScale.x / 2,
		(int)m_fptPos.y - m_fptScale.y / 2,
		(int)m_fptPos.x + m_fptScale.x / 2,
		(int)m_fptPos.y + m_fptScale.y / 2);	

	Component_Render(hDC);
}

void CGameObject::Component_Render(HDC hDC)
{
	if (nullptr != m_pCollider)
	{
		m_pCollider->Render(hDC);
	}
}

void CGameObject::CreateCollider()
{
	m_pCollider = new CCollider();
	m_pCollider->m_pOwner = this;
}

CCollider* CGameObject::GetCollider()
{
	return m_pCollider;
}


