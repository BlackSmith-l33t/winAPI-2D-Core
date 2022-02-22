#include "framework.h"
#include "CCore.h"
#include "CGameObject.h"
#include "CScene.h"

CScene scene_stage1;
CScene scene_stage2;
bool stageChange = true;

CCore::CCore()
{
	// ���� ȭ���� �׸��� ���� DC �ڵ鰪 �ʱ�ȭ
	m_hDC = 0;	
	m_hMemDC = 0;
	m_hBMP = 0;
}

CCore::~CCore()
{
	// ���� �ھ� ���� ������ DC �ڵ鰪 �ݳ�
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
}

void CCore::update()
{
	CTimeManager::getInst()->update();
	CKeyManager::getInst()->Update();
	
	// ���� ���� ���� ����
	// GetAsyncKeyState : �޽��� ť�� Ű �Է��� �޴� ����� �ƴ�  ���� ������ Ű �Է»��¸� Ȯ��
	if (KEYDOWN(VK_SPACE))
	{
		stageChange = !stageChange;
	}
}

void CCore::render()
{
	// ���� ������ ��뵵 memDC�� �׸��� �۾� ����
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	if (stageChange)
	{
		scene_stage1.Render(m_hMemDC);
	}
	else
	{
		scene_stage2.Render(m_hMemDC);
	}

	// �����ʿ� ��ܿ� FPS ǥ��
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);

	// memDC�� �׸� �۾��� �ٽ� ������ DC�� ����
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}

void CCore::init()
{
	// ���� �ʱ�ȭ �۾� ����
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->Init();
	
	// ���� �������� DC �ڵ鰪 ��������
	m_hDC = GetDC(hWnd);	

	// ���� ���۸��� �޸� DC�� ��Ʈ�� ����
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	CGameObject* obj = new CGameObject;
	obj->SetPos(fPoint(100, 100));
	obj->SetScale(fPoint(200, 200));
	scene_stage1.AddObject(obj, GROUP_GAMEOBJ::PLAYER);

	CGameObject* monObj = new CGameObject;
	monObj->SetPos(fPoint(200, 200));
	monObj->SetScale(fPoint(100, 100));
	scene_stage2.AddObject(monObj, GROUP_GAMEOBJ::MONSTER);
}
  