#include "framework.h"
#include "CGameObject.h"

CGameObject::CGameObject()
{
}

CGameObject::~CGameObject()
{
}

//void CGameObject::Render(HDC hDC)
//{
//	 Test용 (지워야 할 것)
//	Rectangle(hDC,
//		m_fptPos.x - m_fptPos.x / 2,
//		m_fptPos.y - m_fptPos.y / 2,
//		m_fptPos.x + m_fptPos.x / 2,
//		m_fptPos.y + m_fptPos.y / 2
//	);
//}

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
