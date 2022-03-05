#include "framework.h"
#include "CGameObject.h"
#include "CCollider.h"
#include "CAnimator.h"

CGameObject::CGameObject()
{
	m_fptPos = {};
	m_fptScale = {};
	m_pCollider = nullptr;
	m_bAlive = true;
}

CGameObject::CGameObject(const CGameObject& other)
{
	m_strName = other.m_strName;
	m_fptPos = other.m_fptPos;
	m_fptScale = other.m_fptScale;
	m_pCollider = nullptr;
	m_pAnimator = nullptr;
	m_bAlive = true;

	if (nullptr != other.m_pCollider)
	{
		m_pCollider = new CCollider(*other.m_pCollider);
		m_pCollider->m_pOwner = this;
	}
	if (nullptr != other.m_pAnimator)
	{
		m_pAnimator = new CAnimator(*other.m_pAnimator);
		m_pAnimator->m_pOwner = this;
	}
}

CGameObject::~CGameObject()
{
	if (nullptr != m_pCollider)
	{
		delete m_pCollider;
	}
	if (nullptr != m_pAnimator)
	{
		delete m_pAnimator;
	}
}

void CGameObject::SetDead()
{
	m_bAlive = false;
}

void CGameObject::SetPos(fPoint pos)
{
	m_fptPos = pos;
}

void CGameObject::SetScale(fPoint scale)
{
	m_fptScale = scale;
}

void CGameObject::SetName(wstring name)
{
	m_strName = name;
}

wstring CGameObject::GetName()
{
	return m_strName;
}

bool CGameObject::isDead()
{
	return !m_bAlive;
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
	if (nullptr != m_pAnimator)
	{
		m_pAnimator->render(hDC);
	}
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

CAnimator* CGameObject::GetAnimator()
{
	return m_pAnimator;
}

void CGameObject::CreateAnimator()
{
	m_pAnimator = new CAnimator;
	m_pAnimator->m_pOwner = this;
}

CCollider* CGameObject::GetCollider()
{
	return m_pCollider;
}


