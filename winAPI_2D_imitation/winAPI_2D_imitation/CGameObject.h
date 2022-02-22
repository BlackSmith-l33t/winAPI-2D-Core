#pragma once
class CGameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

public:
	CGameObject();
	~CGameObject();

	virtual void Update() = 0;
	virtual void Render(HDC hDC) = 0;

	void SetPos(fPoint pos);
	void SetScale(fPoint scale);

	fPoint GetPos();
	fPoint GetScale();
};

