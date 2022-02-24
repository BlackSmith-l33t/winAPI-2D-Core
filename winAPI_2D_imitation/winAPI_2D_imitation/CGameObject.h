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
	virtual void Render(HDC hDC);

	fPoint GetPos();
	void SetPos(fPoint pos);
	
	fPoint GetScale();
	void SetScale(fPoint scale);
};

