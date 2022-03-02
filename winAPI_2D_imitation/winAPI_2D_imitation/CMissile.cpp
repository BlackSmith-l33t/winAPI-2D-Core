#include "framework.h"
#include "CMissile.h"

CMissile::CMissile()
{
	m_fVelocity = 200;
	SetScale(fPoint(25, 25));
}

CMissile::~CMissile()
{

}

void CMissile::Update()
{
	fPoint pos = GetPos();

	pos.x += (float)m_fVelocity * m_fvDir.x * DT;
	pos.y += (float)m_fVelocity * m_fvDir.y * DT;

	SetPos(pos);
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
