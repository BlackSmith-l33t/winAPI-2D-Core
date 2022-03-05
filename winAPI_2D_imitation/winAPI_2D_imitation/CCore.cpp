#include "framework.h"
#include "CCore.h"
#include "CGameObject.h"
#include "CScene.h"

bool stageChange = true;

CCore::CCore()
{
	// 게임 화면을 그리기 위한 DC 핸들값 초기화
	m_hDC = 0;	
	m_hMemDC = 0;
	m_hBMP = 0;
	m_arrPen[0] = 0;
	m_arrBrush[0] = 0;
}

CCore::~CCore()
{
	// 게임 코어 종료 시점에 DC 핸들값 반납
	ReleaseDC(hWnd, m_hDC);
	DeleteObject(m_hMemDC);
	DeleteObject(m_hBMP);

	for (int i = 0; i < (int)TYPE_PEN::SIZE; i++)
	{
		DeleteObject(m_arrPen[i]);
	}
}

void CCore::update()
{
	// 이전 update에서 추가된 이벤트를 프레임 초기에 한꺼번에 처리
	CEventManager::getInst()->update();

	CTimeManager::getInst()->update();
	CKeyManager::getInst()->Update();
	CSceneManager::getInst()->Update();
	CCollisionManager::getInst()->update();
	
	// 게임 정보 갱신 진행
}

void CCore::render()
{
	// 게임 정보를 토대도 memDC에 그리기 작업 진행
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	CSceneManager::getInst()->Render(m_hMemDC);

	// 오른쪽에 상단에 FPS 표시
	WCHAR strFPS[6];
	swprintf_s(strFPS, L"%5d", CTimeManager::getInst()->GetFPS());
	TextOutW(m_hMemDC, WINSIZEX - 50, 10, strFPS, 5);

	// memDC에 그린 작업을 다시 윈도우 DC로 복사
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}

void CCore::init()
{
	CreateBrushPen();

	// 게임 초기화 작업 진행
	CPathManager::getInst()->init();
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->Init();
	CSceneManager::getInst()->Init();
	CCollisionManager::getInst()->init();
	
	// 게임 윈도우의 DC 핸들값 가져오기
	m_hDC = GetDC(hWnd);	

	// 더블 버퍼링의 메모리 DC와 비트맵 생성
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);
}

HDC CCore::GetMainDC()
{
	return m_hMemDC;
}

void CCore::CreateBrushPen()
{
	// brush 
	m_arrBrush[(int)TYPE_BRUSH::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	// pen
	m_arrPen[(int)TYPE_PEN::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(int)TYPE_PEN::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
	m_arrPen[(int)TYPE_PEN::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
}

HBRUSH CCore::GetBrush(TYPE_BRUSH brush)
{
	return m_arrBrush[(int)brush];
}

HPEN CCore::GetPen(TYPE_PEN pen)
{
	return m_arrPen[(int)pen];
}
  