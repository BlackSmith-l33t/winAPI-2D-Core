#pragma once
class CCollider;
class CAnimator;

class CGameObject
{
	friend class CEventManager;
private:
	wstring m_strName;
	fPoint m_fptPos;
	fPoint m_fptScale;

	// Component
	CCollider* m_pCollider;
	CAnimator* m_pAnimator;

	bool m_bAlive;
	void SetDead();
public:
	CGameObject();
	CGameObject(const CGameObject& other);
	virtual ~CGameObject();
	virtual CGameObject* Clone() = 0;

	fPoint	GetPos();
	wstring GetName();
	fPoint	GetScale();

	void SetPos(fPoint pos);
	void SetScale(fPoint scale);
	void SetName(wstring name);

	bool isDead();

	virtual void Update() = 0;
	virtual void FinalUpdate() final; // 상속받은 클래스가 더이상 오버라이딩 하는 것을 막아 줌.
	virtual void Render(HDC hDC);
	virtual void Component_Render(HDC hDC);

	CCollider* GetCollider();
	void	   CreateCollider();

	virtual void OnCollision(CCollider* _pOther) {}			// 재정의용 충돌중 가상함수
	virtual void OnCollisionEnter(CCollider* _pOther) {}	// 재정의용 충돌시 가상함수
	virtual void OnCollisionExit(CCollider* _pOther) {}		// 재정의용 탈충돌 가상함수

	CAnimator* GetAnimator(); // 애니메이터 반환
	void	   CreateAnimator();    // 애니메이터 생성
};

