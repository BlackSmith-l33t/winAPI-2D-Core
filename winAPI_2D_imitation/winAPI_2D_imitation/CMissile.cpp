#include "framework.h"
#include "CMissile.h"
#include "CCollider.h"

CMissile::CMissile()
{
	m_fVelocity = 200;
	SetScale(fPoint(25.f, 25.f));
	m_fvDir = fVec2(0, 0);
	SetName(L"Missile_Player");

	CreateCollider();
	GetCollider()->SetScale(fPoint(15.f, 15.f));
}

CMissile::~CMissile()
{

}

CMissile* CMissile::Clone()
{
	return new CMissile(*this);
}

void CMissile::Update()
{
	fPoint pos = GetPos();

	pos.x += m_fVelocity * m_fvDir.x * fDT;
	pos.y += m_fVelocity * m_fvDir.y * fDT;

	SetPos(pos);

	if (pos.x || pos.x > WINSIZEX || pos.y < 0 || pos.y > WINSIZEY)
	{
		DeleteObj(this);
	}
}

void CMissile::Render(HDC hDC)
{
	fPoint pos = GetPos();
	fPoint scale = GetScale();

	Ellipse(hDC,
		(int)(pos.x - scale.x / 2.f),
		(int)(pos.y - scale.y / 2.f),
		(int)(pos.x + scale.x / 2.f),
		(int)(pos.y + scale.y / 2.f));

	Component_Render(hDC);
}

void CMissile::SetDir(fVec2 vec)
{
	m_fvDir = vec;
}

fVec2 CMissile::GetDir()
{
	return m_fvDir;
}

void CMissile::OnCollisionEnter(CCollider* pOther)
{
}
