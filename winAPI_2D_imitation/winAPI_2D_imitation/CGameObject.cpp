#include "framework.h"
#include "CGameObject.h"

CGameObject::CGameObject()
{
}

CGameObject::~CGameObject()
{
}

void CGameObject::Update()
{
	if (KEY(VK_LEFT))
	{
		m_fptPos.x -= 100 * DT;
	}

	if (KEY(VK_RIGHT))
	{
		m_fptPos.x += 100 * DT;
	}

	if (KEY(VK_UP))
	{
		m_fptPos.y -= 100 * DT;
	}

	if (KEY(VK_DOWN))
	{
		m_fptPos.y += 100 * DT;
	}
}

void CGameObject::Render(HDC hDC)
{
	// Test�� (������ �� ��)
	Rectangle(hDC,
		(int)m_fptPos.x - m_fptScale.x / 2,
		(int)m_fptPos.y - m_fptScale.y / 2,
		(int)m_fptPos.x + m_fptScale.x / 2,
		(int)m_fptPos.y + m_fptScale.y / 2
	);	
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
