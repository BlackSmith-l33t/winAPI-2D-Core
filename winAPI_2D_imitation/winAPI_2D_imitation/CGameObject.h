#pragma once
class CCollider;

class CGameObject
{
	friend class CEventManager;
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
	virtual void FinalUpdate() final; // ��ӹ��� Ŭ������ ���̻� �������̵� �ϴ� ���� ���� ��.
	virtual void Render(HDC hDC);
	virtual void Component_Render(HDC hDC);

	CCollider* GetCollider();
	void CreateCollider();

	virtual void OnCollision(CCollider* _pOther) {}			// �����ǿ� �浹�� �����Լ�
	virtual void OnCollisionEnter(CCollider* _pOther) {}	// �����ǿ� �浹�� �����Լ�
	virtual void OnCollisionExit(CCollider* _pOther) {}		// �����ǿ� Ż�浹 �����Լ�
};

