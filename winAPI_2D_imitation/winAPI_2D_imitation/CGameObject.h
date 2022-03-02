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
	virtual void FinalUpdate() final; // ��ӹ��� Ŭ������ ���̻� �������̵� �ϴ� ���� ���� ��.
	virtual void Render(HDC hDC);
	virtual void Component_Render(HDC hDC);

	CCollider* GetCollider();
	void CreateCollider();
};

