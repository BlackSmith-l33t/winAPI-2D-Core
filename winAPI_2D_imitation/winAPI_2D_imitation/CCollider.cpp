#include "framework.h"
#include "CCollider.h"
#include "CGameObject.h"
#include "SelectGDI.h"


CCollider::CCollider()
{
	m_pOwner = nullptr;
	m_fptOffsetPos = {};
	m_fptScale = {};
	m_fptFinalPos = {};
}

CCollider::~CCollider()
{
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

void CCollider::SetOffsetPos(fPoint offset)
{
	m_fptOffsetPos = offset;
}

void CCollider::SetFinalPos(fPoint pos)
{
	m_fptFinalPos = pos;
}

void CCollider::SetScale(fPoint scale)
{
	m_fptScale = scale;
}


void CCollider::FinalUpdate()
{
	fPoint fptObjPos = m_pOwner->GetPos();
	m_fptFinalPos = fptObjPos + m_fptOffsetPos;
}

void CCollider::Render(HDC hDC)
{
	SelectGDI brush(hDC, TYPE_BRUSH::HOLLOW);
	SelectGDI Pen(hDC, TYPE_PEN::GREEN);

	Rectangle(hDC,
		(int)(m_fptFinalPos.x - m_fptScale.x / 2.f),
		(int)(m_fptFinalPos.y - m_fptScale.y / 2.f),
		(int)(m_fptFinalPos.x + m_fptScale.x / 2.f),
		(int)(m_fptFinalPos.y + m_fptScale.y / 2.f));
}
