#include "framework.h"
#include "CMissile.h"

CMissile::CMissile()
{
	m_fVelocity = 25;
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

void CMissile::SetDir(fVec2 vec)
{
	m_fvDir = vec;
}

fVec2 CMissile::GetDir()
{
	return m_fvDir;
}
