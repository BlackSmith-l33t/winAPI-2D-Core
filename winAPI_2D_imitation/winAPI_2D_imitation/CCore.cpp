#include "framework.h"
#include "CCore.h"
#include "CGameObject.h"
<<<<<<< HEAD

CGameObject object;
=======
#include "CScene.h"

bool stageChange = true;
>>>>>>> Core

CCore::CCore()
{
	// ���� ȭ���� �׸��� ���� DC �ڵ鰪 �ʱ�ȭ
<<<<<<< HEAD
	m_hDC	 = 0;	
	m_hMemDC = 0;
	m_hBMP	 = 0;
=======
	m_hDC = 0;	
	m_hMemDC = 0;
	m_hBMP = 0;
>>>>>>> Core
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
<<<<<<< HEAD

	// ���� ���� ���� ����
	object.Update();
=======
	CSceneManager::getInst()->Update();
	
	// ���� ���� ���� ����
>>>>>>> Core
}

void CCore::render()
{
	// ���� ������ ��뵵 memDC�� �׸��� �۾� ����
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

<<<<<<< HEAD
	object.Render(m_hMemDC);
=======
	CSceneManager::getInst()->Render(m_hMemDC);
>>>>>>> Core

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
	CPathManager::getInst()->init();
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->Init();
	CSceneManager::getInst()->Init();
	
	// ���� �������� DC �ڵ鰪 ��������
	m_hDC = GetDC(hWnd);	

	// ���� ���۸��� �޸� DC�� ��Ʈ�� ����
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);
}

<<<<<<< HEAD
	object.SetPos(fPoint(200, 200));
	object.SetScale(fPoint(100, 100));
=======
HDC CCore::GetMainDC()
{
	return m_hMemDC;
>>>>>>> Core
}
  