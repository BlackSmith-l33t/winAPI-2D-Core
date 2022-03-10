#include "framework.h"
#include "CButtonUI.h"
#include "CScene_Tool.h"
#include "CTexture.h"

CButtonUI::CButtonUI()
	: CUI(false)
{
	m_pFunc = nullptr;
	m_pParam1 = 0;
	m_pParam2 = 0;
}

CButtonUI::~CButtonUI()
{
}

CButtonUI* CButtonUI::Clone()
{
	return new CButtonUI(*this);
}

void CButtonUI::MouseOn()
{
	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

	CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
	assert(pToolScene);

	CTexture* pTex = CResourceManager::getInst()->FindTexture(L"Exit_Button");

	UINT iWidth = pTex->GetBmpWidth();
	UINT iHeight = pTex->GetBmpHeight();

	BitBlt(pTex->GetDC(),
		(int)(100),
		(int)(180),
		(int)(20),
		(int)(20),
		pTex->GetDC(),
		(int)(pTex->GetBmpWidth()),
		(int)(pTex->GetBmpHeight()),
		SRCCOPY);

	// TODO : 0310 버튼 색깔 바꾸기 시도 중 
}

void CButtonUI::MouseLbtnDown()
{
}

void CButtonUI::MouseLbtnUp()
{

}

void CButtonUI::MouseLbtnClicked()
{
	if (nullptr != m_pFunc)
	{
		m_pFunc(m_pParam1, m_pParam2);
	}
}

void CButtonUI::SetClickedCallBack(BTN_FUNC pFunc, DWORD_PTR param1, DWORD_PTR param2)
{
	m_pFunc = pFunc;
	m_pParam1 = param1;
	m_pParam2 = param2;
}
