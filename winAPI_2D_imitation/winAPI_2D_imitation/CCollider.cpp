#include "framework.h"
#include "CCollider.h"
#include "CGameObject.h"

#include "SelectGDI.h"

UINT CCollider::s_iID = 0;

CCollider::CCollider()
{
	m_pOwner = nullptr;
	m_fptOffsetPos = {};
	m_fptFinalPos = {};
	m_fptScale = {};
	m_iColCount = 0;
	m_iID = s_iID++;
}

CCollider::CCollider(const CCollider& other)
{
	m_pOwner = nullptr;
	m_fptOffsetPos = other.m_fptOffsetPos;
	m_fptFinalPos = other.m_fptFinalPos;
	m_fptScale = other.m_fptScale;
	m_iColCount = other.m_iColCount;
	m_iID = s_iID++;
}

CCollider::~CCollider()
{
}

CGameObject* CCollider::GetObj()
{
	return m_pOwner;
}

fPoint CCollider::GetOffsetPos()
{
	return m_fptOffsetPos;
}

fPoint CCollider::GetFinalPos()
{
	return m_fptFinalPos;
}

fPoint CCollider::GetScale()
{
	return m_fptScale;
}

void CCollider::SetOffsetPos(fPoint offsetPos)
{
	m_fptOffsetPos = offsetPos;
}

void CCollider::SetFinalPos(fPoint finalPos)
{
	m_fptFinalPos = finalPos;
}

void CCollider::SetScale(fPoint scale)
{
	m_fptScale = scale;
}

UINT CCollider::GetID()
{
	return m_iID;
}

void CCollider::FinalUpdate()
{
	fPoint fptObjectPos = m_pOwner->GetPos();
	m_fptFinalPos = fptObjectPos + m_fptOffsetPos;
}

void CCollider::Render(HDC hDC)
{
	TYPE_PEN typePen;
	if (m_iColCount)
		typePen = TYPE_PEN::RED;
	else
		typePen = TYPE_PEN::GREEN;

	SelectGDI brush(hDC, TYPE_BRUSH::HOLLOW);
	SelectGDI pen(hDC, typePen);

	Rectangle(hDC,
		(int)(m_fptFinalPos.x - m_fptScale.x / 2.f),
		(int)(m_fptFinalPos.y - m_fptScale.y / 2.f),
		(int)(m_fptFinalPos.x + m_fptScale.x / 2.f),
		(int)(m_fptFinalPos.y + m_fptScale.y / 2.f));
}

void CCollider::OnCollision(CCollider* pOther)
{
	m_pOwner->OnCollision(pOther);
}

void CCollider::OnCollisionEnter(CCollider* pOther)
{
	m_pOwner->OnCollisionEnter(pOther);
	m_iColCount++;
}

void CCollider::OnCollisionExit(CCollider* pOther)
{
	m_pOwner->OnCollisionExit(pOther);
	m_iColCount--;
}
