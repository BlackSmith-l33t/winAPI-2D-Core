#include "framework.h"
#include "CSceneManager.h"
#include "framework.h"
#include "CSceneManager.h"
#include "CScene_Start.h"
#include "CScene_Stage_01.h"

CSceneManager::CSceneManager()
{
	for (int i = 0; i < (int)GROUP_SCENE::SIZE; i++)
	{
		m_arrScene[i] = nullptr;
	}
	m_pCurrScene = nullptr;
}

CSceneManager::~CSceneManager()
{
	for (int i = 0; i < (int)GROUP_SCENE::SIZE; i++)
	{
		if (nullptr != m_arrScene[i])
		{
			delete m_arrScene[i];
		}
	}
}

void CSceneManager::changeScene(GROUP_SCENE group)
{
	if (m_arrScene[(int)group] == m_pCurrScene)
	{
		return;
	}

	m_pCurrScene->Exit();
	m_pCurrScene = m_arrScene[(int)group];
	m_pCurrScene->Enter();
}

void CSceneManager::Update()
{
	if (KEYDOWN(VK_SPACE))
	{
		changeScene(GROUP_SCENE::STAGE_01);
	}
	else if (KEYDOWN(VK_ESCAPE))
	{
		// TODO : 게임 화면에서 ESC 를 누르면 오류 발생. 원인은 아직 찾기 못했음.
		changeScene(GROUP_SCENE::START);
	}
	m_pCurrScene->Update();
}

void CSceneManager::Render(HDC hDC)
{
	m_pCurrScene->Render(hDC);
}

void CSceneManager::Init()
{
	m_arrScene[(int)GROUP_SCENE::START] = new CScene_Start;
	m_arrScene[(int)GROUP_SCENE::START]->SetName(L"Start_Scene");

	m_arrScene[(int)GROUP_SCENE::STAGE_01] = new CScene_Stage_01;
	m_arrScene[(int)GROUP_SCENE::STAGE_01]->SetName(L"Stage1_Scene");

	m_pCurrScene = m_arrScene[(int)GROUP_SCENE::START];
	m_pCurrScene->Enter();
}

