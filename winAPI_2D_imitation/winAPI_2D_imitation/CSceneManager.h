#pragma once
class CScene;

class CSceneManager
{
	SINGLETON(CSceneManager);
	friend class CEventManager;
private:
	CScene* m_arrScene[(int)GROUP_SCENE::SIZE];
	CScene* m_pCurrScene;

	void changeScene(GROUP_SCENE group);
public:	

	void Init();
	void Update();	
	void Render(HDC hDC);

	CScene* GetCurScene();
};