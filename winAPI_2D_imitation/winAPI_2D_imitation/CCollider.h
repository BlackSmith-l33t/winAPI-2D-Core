#pragma once
class CGameObject;

class CCollider
{
	friend class CGameObject;
private:
	CGameObject* m_pOwner;
	fPoint m_fptOffsetPos;
	fPoint m_fptFinalPos;
	fPoint m_fptScale;

public:
	CCollider();
	~CCollider();

	fPoint GetOffsetPos();
	fPoint GetFinalPos();
	fPoint GetScale();

	void SetOffsetPos(fPoint offset);
	void SetFinalPos(fPoint pos);
	void SetScale(fPoint scale);

	void FinalUpdate();
	void Render(HDC hDC);
};

