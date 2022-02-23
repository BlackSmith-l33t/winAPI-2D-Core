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

	void Update();
	void Init();
	void Render(HDC hDC);


};

