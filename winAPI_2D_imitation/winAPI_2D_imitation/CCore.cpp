#include "framework.h"
#include "CCore.h"
#include "CGameObject.h"
// CCore* CCore::_instance = NULL;
CGameObject object;

CCore::CCore()
{
	// 게임 화면을 그리기 위한 DC 핸들값 초기화
	m_hDC = 0;	
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

	fPoint pos = object.GetPos();
	// 게임 정보 갱신 진행
	// GetAsyncKeyState : 메시지 큐에 키 입력을 받는 방식이 아닌  현재 상태의 키 입력상태를 확인
	if (KEY(VK_LEFT))
	{
		pos.x -= 100 * DT;
	}

	if (KEY(VK_RIGHT))
	{
		pos.x += 100 * DT;
	}

	if (KEY(VK_UP))
	{
		pos.y -= 100 * DT;
	}

	if (KEY(VK_DOWN))
	{
		pos.y += 100 * DT;
	}

	object.SetPos(pos);
}

void CCore::render()
{	
	// 게임 정보를 토대도 memDC에 그리기 작업 진행
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	Rectangle(m_hMemDC,
		object.GetPos().x - object.GetScale().x / 2,
		object.GetPos().y - object.GetScale().y / 2,
		object.GetPos().x + object.GetScale().x / 2,
		object.GetPos().y + object.GetScale().y / 2);

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
	CTimeManager::getInst()->init();
	CKeyManager::getInst()->Init();
	
	// 게임 윈도우의 DC 핸들값 가져오기
	m_hDC = GetDC(hWnd);	

	// 더블 버퍼링의 메모리 DC와 비트맵 생성
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	object = CGameObject(fPoint(100, 100), fPoint{ 100, 100 });
}
