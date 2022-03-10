#include "framework.h"
#include "CScene_Tool.h"
#include "CTile.h"
#include "resource.h"
#include "CScene.h"
#include "CTexture.h"
#include "commdlg.h"
#include "CUI.h"
#include "CPanelUI.h"
#include "CButtonUI.h"

INT_PTR CALLBACK TileWinProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

CScene_Tool::CScene_Tool()
{
	m_hWnd = 0;
	m_iIdx = 0;
	m_velocity = 200;
}

CScene_Tool::~CScene_Tool()
{
}

void CScene_Tool::update()
{
	CScene::update();

	if (KeyDown(VK_TAB))
	{
		ChangeScn(GROUP_SCENE::START);
	}

	if (Key('A'))
	{
		CCameraManager::getInst()->Scroll(fVec2(-1, 0), m_velocity);
	}
	if (Key('D'))
	{
		CCameraManager::getInst()->Scroll(fVec2(1, 0), m_velocity);
	}
	if (Key('W'))
	{
		CCameraManager::getInst()->Scroll(fVec2(0, -1), m_velocity);
	}
	if (Key('S'))
	{
		CCameraManager::getInst()->Scroll(fVec2(0, 1), m_velocity);
	}

	SetTileIdx();
}

void ChangeScene(DWORD_PTR, DWORD_PTR)
{
	ChangeScn(GROUP_SCENE::START);
}

void CScene_Tool::Enter()
{
	CCameraManager::getInst()->SetLookAt(fPoint(WINSIZEX / 2.f, WINSIZEY / 2.f));

	CreateTile(5, 5);

	m_hWnd = CreateDialog(hInst, MAKEINTRESOURCE(IDD_TILEBOX), hWnd, TileWinProc);
	ShowWindow(m_hWnd, SW_SHOW);

	// UI ����	
	CUI* pPanelUI = new CPanelUI();
	pPanelUI->SetScale(fPoint(300.f, 350.f));
	pPanelUI->SetPos(fPoint(860, 176.f));		// UI�� ī�޶��� ��ġ�� ������� ���� ��ǥ�� ���� ����
	AddObject(pPanelUI, GROUP_GAMEOBJ::UI);

	CUI* pButtonUI_Exit = new CButtonUI();
	pButtonUI_Exit->SetScale(fPoint(20.f, 20.f));
	pButtonUI_Exit->SetPos(fPoint(270.f, 10.f));
	pPanelUI->AddChild(pButtonUI_Exit);

	CUI* pPanelUI_Inside = new CPanelUI();
	pPanelUI_Inside->SetScale(fPoint(200.f, 200.f));
	pPanelUI_Inside->SetPos(fPoint(pPanelUI->GetCenterPos().x - pPanelUI_Inside->GetScale().x / 2, pPanelUI->GetCenterPos().y - pPanelUI_Inside->GetScale().y / 2));
	pPanelUI->AddChild(pPanelUI_Inside);

	CUI* pButtonUI_01 = new CButtonUI();
	pButtonUI_01->SetScale(fPoint(80.f, 40.f));
	pButtonUI_01->SetPos(fPoint(10.f, 120.f));
	pPanelUI_Inside->AddChild(pButtonUI_01);

	CUI* pButtonUI_02 = new CButtonUI();
	pButtonUI_02->SetScale(fPoint(80.f, 40.f));
	pButtonUI_02->SetPos(fPoint(110.f, 120.f));
	pPanelUI_Inside->AddChild(pButtonUI_02);

	CUI* pButtonUI_Ok = new CButtonUI();
	pButtonUI_Ok->SetScale(fPoint(100.f, 40.f));
	pButtonUI_Ok->SetPos(fPoint(pPanelUI->GetCenterPos().x - pButtonUI_Ok->GetScale().x / 2, 300.f));
	pPanelUI->AddChild(pButtonUI_Ok);

	//// UI ����
	//CUI* pClonePanel = pPanelUI->Clone();
	//pClonePanel->SetPos(pClonePanel->GetPos() + fPoint(-500.f, 0.f));
	//AddObject(pClonePanel, GROUP_GAMEOBJ::UI);

	//CButtonUI* pBtnUI = new CButtonUI;
	//pBtnUI->SetScale(fPoint(30.f, 50.f));
	//pBtnUI->SetPos(fPoint(150.f, 10.f));
	//pBtnUI->SetClickedCallBack(ChangeScene, 0, 0);	// �߰� ������ �ʿ�� ���� �ʴ� ����
	//AddObject(pBtnUI, GROUP_GAMEOBJ::UI);
	//pPanelUI->AddChild(pBtnUI);
}

void CScene_Tool::Exit()
{
	EndDialog(m_hWnd, IDOK);
	DeleteAll();
}

void CScene_Tool::SetIdx(UINT idx)
{
	m_iIdx = idx;
}

void CScene_Tool::SetTileIdx()
{
	if (Key(VK_LBUTTON))
	{
		fPoint fptMousePos = MousePos();
		fptMousePos = CCameraManager::getInst()->GetRealPos(fptMousePos);

		int iTileX = (int)GetTileX();
		int iTileY = (int)GetTileY();

		int iCol = (int)fptMousePos.x / CTile::SIZE_TILE;
		int iRow = (int)fptMousePos.y / CTile::SIZE_TILE;

		if (fptMousePos.x < 0.f || iTileX <= iCol ||
			fptMousePos.y < 0.f || iTileY <= iRow)
		{
			return;		// Ÿ���� ���� ��ġ ����
		}

		UINT iIdx = iRow * iTileX + iCol;
		const vector<CGameObject*>& vecTile = GetGroupObject(GROUP_GAMEOBJ::TILE);
		((CTile*)vecTile[iIdx])->SetImgIdx(m_iIdx);
	}
}

void CScene_Tool::SaveTile(const wstring& strPath)
{
	FILE* pFile = nullptr;

	_wfopen_s(&pFile, strPath.c_str(), L"wb");		// w : write, b : binary
	assert(pFile);

	UINT xCount = GetTileX();
	UINT yCount = GetTileY();

	fwrite(&xCount, sizeof(UINT), 1, pFile);
	fwrite(&yCount, sizeof(UINT), 1, pFile);

	const vector<CGameObject*>& vecTile = GetGroupObject(GROUP_GAMEOBJ::TILE);

	for (UINT i = 0; i < vecTile.size(); i++)
	{
		((CTile*)vecTile[i])->Save(pFile);
	}

	fclose(pFile);
}

void CScene_Tool::SaveTileData()
{
	OPENFILENAME ofn = {};

	ofn.lStructSize = sizeof(OPENFILENAME);  // ����ü ������.
	ofn.hwndOwner = hWnd;					// �θ� ������ ����.
	wchar_t szName[256] = {};
	ofn.lpstrFile = szName; // ���߿� �ϼ��� ��ΰ� ä���� ���� ����.
	ofn.nMaxFile = sizeof(szName); // lpstrFile�� ������ ������ ���� ��.
	ofn.lpstrFilter = L"ALL\0*.*\0tile\0*.tile"; // ���� ����
	ofn.nFilterIndex = 0; // �⺻ ���� ����. 0�� all�� �ʱ� ���õ�. ó����.
	ofn.lpstrFileTitle = nullptr; // Ÿ��Ʋ ��
	ofn.nMaxFileTitle = 0; // Ÿ��Ʋ �� ���ڿ� ũ��. nullptr�̸� 0.
	wstring strTileFolder = CPathManager::getInst()->GetContentPath();
	strTileFolder += L"tile";
	ofn.lpstrInitialDir = strTileFolder.c_str(); // �ʱ���. �츮�� Ÿ�� �����Ұű� ������, content->tile ��η� �ص���.
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; // ��Ÿ��

	if (GetSaveFileName(&ofn))
	{
		SaveTile(szName);
	}
}

void CScene_Tool::LoadTileData()
{
	OPENFILENAME ofn = {};

	ofn.lStructSize = sizeof(OPENFILENAME);  // ����ü ������.
	ofn.hwndOwner = hWnd; // �θ� ������ ����.
	wchar_t szName[256] = {};
	ofn.lpstrFile = szName; // ���߿� �ϼ��� ��ΰ� ä���� ���� ����.
	ofn.nMaxFile = sizeof(szName); // lpstrFile�� ������ ������ ���� ��.
	ofn.lpstrFilter = L"ALL\0*.*\0tile\0*.tile"; // ���� ����
	ofn.nFilterIndex = 0; // �⺻ ���� ����. 0�� all�� �ʱ� ���õ�. ó����.
	ofn.lpstrFileTitle = nullptr; // Ÿ��Ʋ ��
	ofn.nMaxFileTitle = 0; // Ÿ��Ʋ �� ���ڿ� ũ��. nullptr�̸� 0.
	wstring strTileFolder = CPathManager::getInst()->GetContentPath();
	strTileFolder += L"tile";
	ofn.lpstrInitialDir = strTileFolder.c_str(); // �ʱ���. �츮�� Ÿ�� �����Ұű� ������, content->tile ��η� �ص���.
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; // ��Ÿ��

	if (GetOpenFileName(&ofn))
	{
		LoadTile(szName);
	}
}

// ���� ��ȭ ������ �޽��� ó�����Դϴ�.
INT_PTR CALLBACK TileWinProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

			CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
			assert(pToolScene);

			pToolScene->SaveTileData();

			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == ID_LOADING)
		{
			CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

			CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
			assert(pToolScene);

			pToolScene->LoadTileData();

			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDC_BUTTON_SIZE)
		{
			int x = GetDlgItemInt(hDlg, IDC_EDIT_SIZEX, nullptr, false);
			int y = GetDlgItemInt(hDlg, IDC_EDIT_SIZEY, nullptr, false);

			CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

			CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
			assert(pToolScene);

			pToolScene->DeleteGroup(GROUP_GAMEOBJ::TILE);
			pToolScene->CreateTile(x, y);
		}
		else if (LOWORD(wParam) == IDC_BUTTON_TILE)
		{
			int m_iIdx = GetDlgItemInt(hDlg, IDC_EDIT_TILE, nullptr, false);

			CScene* pCurScene = CSceneManager::getInst()->GetCurScene();

			CScene_Tool* pToolScene = dynamic_cast<CScene_Tool*>(pCurScene);
			assert(pToolScene);

			CTexture* pTex = CResourceManager::getInst()->FindTexture(L"Tile");

			UINT iWidth = pTex->GetBmpWidth();
			UINT iHeight = pTex->GetBmpHeight();

			UINT iMaxRow = iHeight / CTile::SIZE_TILE;
			UINT iMaxCol = iWidth / CTile::SIZE_TILE;

			UINT iCurRow = (m_iIdx / iMaxCol) % iMaxRow;
			UINT iCurCol = (m_iIdx % iMaxCol);

			// �ӽ÷� �̹��� ���
			BitBlt(GetDC(hDlg),
				(int)(100),
				(int)(180),
				(int)(CTile::SIZE_TILE),
				(int)(CTile::SIZE_TILE),
				pTex->GetDC(),
				(int)(iCurCol * CTile::SIZE_TILE),
				(int)(iCurRow * CTile::SIZE_TILE),
				SRCCOPY);

			pToolScene->SetIdx(m_iIdx);
		}
		else if (LOWORD(wParam) == IDCANCEL)
		{
			DestroyWindow(hDlg);
		}
		break;
	}
	return (INT_PTR)FALSE;
}