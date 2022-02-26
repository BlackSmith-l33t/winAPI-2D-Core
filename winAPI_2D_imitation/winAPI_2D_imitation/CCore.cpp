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
	// 게임 화면을 그리기 위한 DC 핸들값 초기화
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
	// 게임 코어 종료 시점에 DC 핸들값 반납
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);
}

void CCore::update()
{
	CTimeManager::getInst()->update();
	CKeyManager::getInst()->Update();
<<<<<<< HEAD

	// 게임 정보 갱신 진행
	object.Update();
=======
	CSceneManager::getInst()->Update();
	
	// 게임 정보 갱신 진행
>>>>>>> Core
}

void CCore::render()
{
	// 게임 정보를 토대도 memDC에 그리기 작업 진행
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

<<<<<<< HEAD
	object.Render(m_hMemDC);
=======
	CSceneManager::getInst()->Render(m_hMemDC);
>>>>>>> Core

	// 오른쪽에 상단에 FPS 표시
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);

	// memDC에 그린 작업을 다시 윈도우 DC로 복사
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}

void CCore::init()
{
	// 게임 초기화 작업 진행
	CPathManager::getInst()->init();
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->Init();
	CSceneManager::getInst()->Init();
	
	// 게임 윈도우의 DC 핸들값 가져오기
	m_hDC = GetDC(hWnd);	

	// 더블 버퍼링의 메모리 DC와 비트맵 생성
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
  