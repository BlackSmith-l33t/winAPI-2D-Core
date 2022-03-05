#include "framework.h"
#include "CScene.h"
#include "CGameObject.h"

CScene::CScene()
{
	m_strName = L"";
}

CScene::~CScene()
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			delete m_arrObj[i][j];
		}
	}
}

void CScene::Update()
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			if (!m_arrObj[i][j]->isDead())
				m_arrObj[i][j]->Update();
		}
	}
}

void CScene::FinalUpdate()
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (int j = 0; j < m_arrObj[i].size(); j++)
		{
			m_arrObj[i][j]->FinalUpdate();
		}
	}
}

void CScene::Render(HDC hDC)
{
	for (int i = 0; i < (int)GROUP_GAMEOBJ::SIZE; i++)
	{
		for (vector<CGameObject*>::iterator iter = m_arrObj[i].begin(); iter != m_arrObj[i].end();)
		{
			if (!(*iter)->isDead())
			{
				(*iter)->Render(hDC);
				iter++;
			}
			else
			{
				iter = m_arrObj[i].erase(iter);
			}
		}
	}
}

void CScene::SetName(const wstring& strName)
{
	m_strName = strName;
}

wstring CScene::GetName()
{
	return m_strName;
}

void CScene::AddObject(CGameObject* pObj, GROUP_GAMEOBJ type)
{
	m_arrObj[(int)type].push_back(pObj);
}

const vector<CGameObject*>& CScene::GetGroupObject(GROUP_GAMEOBJ group)
{
	return m_arrObj[(UINT)group];
}

void CScene::DeleteGroup(GROUP_GAMEOBJ group)
{
	for (int i = 0; i < m_arrObj[(UINT)group].size(); i++)
	{
		delete m_arrObj[(UINT)group][i];
	}
	m_arrObj[(UINT)group].clear();
}

void CScene::DeleteAll()
{
	for (int i = 0; i < (UINT)GROUP_GAMEOBJ::SIZE; i++)
	{
		DeleteGroup((GROUP_GAMEOBJ)i);
	}
}

