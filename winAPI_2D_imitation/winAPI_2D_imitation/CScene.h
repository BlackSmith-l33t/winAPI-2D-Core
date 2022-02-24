#pragma once
// ���� ����: �ش� Ŭ������ ������ ������ ����� �� �ְ� ����.
// 1. ��������� ������ ȣ��Ǿ� #Prame once ����θ� Ȯ�� �Ұ��� ���� �ذ�
// 2. ������ �ӵ��� ����.
class CGameObject;

class CScene
{
	vector<CGameObject*>  m_arrObj[(int)GROUP_GAMEOBJ::SIZE];
	wstring				  m_strName; // wstring =>  2byte �ѱ۱��� �����ϱ� ���ؼ� ����Ѵ�.

public:
	CScene();
	virtual ~CScene();

	virtual void Update();
	virtual void Render(HDC hDC);

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	void	SetName(const wstring& strName);
	wstring GetName();

	void	AddObject(CGameObject* pObj, GROUP_GAMEOBJ type);

protected:
	void Clear();
};

