#pragma once
class CGameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

public:
	CGameObject();
	virtual ~CGameObject();

	virtual void Update() = 0;
	virtual void Render(HDC hDC) = 0;

	fPoint GetPos();
	void SetPos(fPoint pos);
	
	fPoint GetScale();
	void SetScale(fPoint scale);	
};

