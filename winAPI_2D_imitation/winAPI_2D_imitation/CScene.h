#pragma once

// 전방 선언 : 해당 클래스의 포인터 변수를 사용할 수 있게 해줌.
// 1. 헤더파일이 여러번 호출되어 #pragma에 의해 선언부를 확인 불가한 문제 해결
// 2. 컴파일 속도를 줄임
class CGameObject;

class CScene
{
private:
	vector<CGameObject*> m_arrObj[(int)GROUP_GAMEOBJ::SIZE];
	wstring m_strName;

	UINT m_iTileX;
	UINT m_iTileY;

public:
	CScene();
	virtual ~CScene();

	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC hDC);

	void render_tile(HDC hDC);

	virtual void Enter() = 0;	// 해당 씬에 진입시 호출
	virtual void Exit() = 0;	// 해당 씬을 탈출시 호출

	virtual void Enter() = 0;
	virtual void Exit() = 0;

	void SetName(const wstring& strName);
	wstring GetName();
	UINT GetTileX();
	UINT GetTileY();

	const vector<CGameObject*>& GetGroupObject(GROUP_GAMEOBJ group);
	void AddObject(CGameObject* pObj, GROUP_GAMEOBJ group);
	void DeleteGroup(GROUP_GAMEOBJ group);
	void DeleteAll();

	void CreateTile(UINT xSize, UINT ySize);
	void LoadTile(const wstring& strPath);
};

