#pragma once
// 전방 선언: 해당 클래스의 포인터 변수를 사용할 수 있게 해줌.
// 1. 헤더파일이 여러번 호출되어 #Prame once 선언부를 확인 불가한 문제 해결
// 2. 컴파일 속도를 줄임.
class CGameObject;

class CScene
{
	vector<CGameObject*> m_arrObj[(int)GROUP_GAMEOBJ::SIZE];
	wstring m_strName;

public:
	CScene();
	virtual ~CScene();

	virtual void Update();
	virtual void Render(HDC hDC);	

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	void SetName(const wstring& strName);
	wstring GetName();

	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ group);
protected:
	void Clear();
};

