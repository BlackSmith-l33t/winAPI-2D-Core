#pragma once
class CGameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

public:
	CGameObject();
	~CGameObject();

<<<<<<< HEAD
	virtual void Update();
	virtual void Render(HDC hDC);

	void SetPos(fPoint pos);
	void SetScale(fPoint scale);
=======
	virtual void Update() = 0;
	virtual void Render(HDC hDC);
>>>>>>> Core

	fPoint GetPos();
	void SetPos(fPoint pos);
	
	fPoint GetScale();
	void SetScale(fPoint scale);
};

