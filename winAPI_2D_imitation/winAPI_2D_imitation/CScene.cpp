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
			m_arrObj[i][j]-
		}
	}
}

void CScene::Render(HDC hDC)
{

}

void CScene::SetName(const wstring& strName)
{

}

wstring CScene::GetName()
{
	return wstring();
}

void CScene::AddObject(CGameObject* pObj, GROUP_GAMEOBJ type)
{

}
