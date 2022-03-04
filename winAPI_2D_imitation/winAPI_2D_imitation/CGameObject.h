#pragma once
class CCollider;

class CGameObject
{
private:
	wstring m_strName;
	fPoint m_fptPos;
	fPoint m_fptScale;

	// Component
	CCollider* m_pCollider;

	bool m_bAlive;
	void SetDead();
public:
	CGameObject();
	~CGameObject();

	fPoint GetPos();
	void SetPos(fPoint pos);

	fPoint GetScale();
	void SetScale(fPoint scale);

	void SetName(wstring name);
	wstring GetName();

	bool isDead();

	virtual void Update() = 0;
	virtual void FinalUpdate() final; // 상속받은 클래스가 더이상 오버라이딩 하는 것을 막아 줌.
	virtual void Render(HDC hDC);
	virtual void Component_Render(HDC hDC);

	CCollider* GetCollider();
	void CreateCollider();

	virtual void OnCollision(CCollider* _pOther) {}			// 재정의용 충돌중 가상함수
	virtual void OnCollisionEnter(CCollider* _pOther) {}	// 재정의용 충돌시 가상함수
	virtual void OnCollisionExit(CCollider* _pOther) {}		// 재정의용 탈충돌 가상함수
};

