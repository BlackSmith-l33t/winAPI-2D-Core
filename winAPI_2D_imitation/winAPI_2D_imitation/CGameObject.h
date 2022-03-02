#pragma once
class CCollider;

class CGameObject
{
private:
	fPoint m_fptPos;
	fPoint m_fptScale;

	CCollider* m_pCollider;
public:
	CGameObject();
	~CGameObject();

	fPoint GetPos();
	void SetPos(fPoint pos);

	fPoint GetScale();
	void SetScale(fPoint scale);

	virtual void Update() = 0;
	virtual void FinalUpdate() final; // 상속받은 클래스가 더이상 오버라이딩 하는 것을 막아 줌.
	virtual void Render(HDC hDC);
	virtual void Component_Render(HDC hDC);

	CCollider* GetCollider();
	void CreateCollider();
};

