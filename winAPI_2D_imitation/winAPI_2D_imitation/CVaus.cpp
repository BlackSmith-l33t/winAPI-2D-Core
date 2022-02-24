#include "framework.h"
#include "CVaus.h"

CVaus::CVaus()
{
	SetScale(fPoint(VAUSX, VAUSY));
	m_dVausSpeed = 600;
}

CVaus::~CVaus()
{
}

void CVaus::Update()
{
	fPoint pos = GetPos();
	if (KEY(VK_LEFT))
	{
		pos.x -= m_dVausSpeed * DT;
	}

	if (KEY(VK_RIGHT))
	{
		pos.x += m_dVausSpeed * DT;
	}

	SetPos(pos);
}

void CVaus::Render(HDC hDC)
{
	Rectangle(hDC,
		(int)(GetPos().x - GetScale().x / 2),
		(int)(GetPos().y - GetScale().y / 2),
		(int)(GetPos().x + GetScale().x / 2),
		(int)(GetPos().y + GetScale().y / 2)
	);
}
