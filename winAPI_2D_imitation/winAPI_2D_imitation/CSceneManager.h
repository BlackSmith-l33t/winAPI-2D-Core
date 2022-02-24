#pragma once
class CScene;

class CSceneManager
{
	SINGLETON(CSceneManager);

private:
	CScene* m_arrScene[(int)GROUP_SCENE::SIZE];
	CScene* m_pCurrScene;
public:
	void changeScene(GROUP_SCENE group);

	void Init();
	void Update();	
	void Render(HDC hDC);

	CScene* GetCurScene();
};