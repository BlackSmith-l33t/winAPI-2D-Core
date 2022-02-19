#include "framework.h"
#include "CGameObject.h"
#include "CCore.h"

// CCore* CCore::_instance = NULL;
CGameObject object;

CCore::CCore()
{
	// 게임 화면을 그리기 위한 DC 핸들값 초기화
	m_hDC = 0;
	m_hMemDC = 0;
	m_hBMP = 0;
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
	// 게임 정보 갱신 진행
	// GetAsyncKeyState : 메시지 큐에 키 입력을 받는 방식이 아닌  현재 상태의 키 입력상태를 확인
}

void CCore::render()
{	
	// 게임 정보를 토대도 memDC에 그리기 작업 진행

	// memDC에 그린 작업을 다시 윈도우 DC로 복사
	BitBlt(m_hDC, 0, 0, WINSIZEX, WINSIZEY, m_hMemDC, 0, 0, SRCCOPY);
}

void CCore::init()
{
	// 게임 초기화 작업 진행

	// 게임 윈도우의 DC 핸들값 가져오기
	m_hDC = GetDC(hWnd);	

	// 더블 버퍼링의 메모리 DC와 비트맵 생성
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);
}
