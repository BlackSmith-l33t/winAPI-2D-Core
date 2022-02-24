#include "framework.h"
#include "CBall.h"

CBall::CBall()
{
	SetScale(fPoint(BALL_RADIUS, BALL_RADIUS));
	m_fVelocity = 0.2f;
	m_fDistance = 0.f;
	m_bIsUpDir  = true;
}

CBall::~CBall()
{
}

void CBall::Update()
{
}

void CBall::Render(HDC hDC)
{
	Ellipse(hDC,
		GetPos().x - GetScale().x / 2,
		GetPos().y - GetScale().y / 2,
		GetPos().x + GetScale().x / 2,
		GetPos().y + GetScale().y / 2
	);
}
