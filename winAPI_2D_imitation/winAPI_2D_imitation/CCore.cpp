#include "framework.h"
#include "CCore.h"
#include "CGameObject.h"

// CCore* CCore::_instance = NULL;
#define BALL_RADIUS 15

CGameObject vaus;  // TODO : 바우스에 색깔넣기
CGameObject ball;  // TODO : 공에 색깔넣기
fPoint vausPos;
fPoint ballPos;

bool IsStart = false;

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
	vausPos = vaus.GetPos();
	ballPos = ball.GetPos();

	// 게임 정보 갱신 진행
	// GetAsyncKeyState : 메시지 큐에 키 입력을 받는 방식이 아닌  현재 상태의 키 입력상태를 확인
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) // 해당 키가 누려있는지 확인하는 코드
	{
		vausPos.x -= 500 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vausPos.x += 500 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000) // Space를 누르면 게임이 시작됨.
	{
		IsStart = true;
	}

	vaus.SetPos(vausPos);
	ball.SetPos(ballPos);
}

void CCore::render()
{	
	// 게임 정보를 토대도 memDC에 그리기 작업 진행
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);
	float ballSpeed = 0.2;
	//Ellipse(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	Rectangle(m_hMemDC,
		vaus.GetPos().x - vaus.GetScale().x / 2,
		vaus.GetPos().y - vaus.GetScale().y / 2,
		vaus.GetPos().x + vaus.GetScale().x / 2,
		vaus.GetPos().y + vaus.GetScale().y / 2);

	Ellipse(m_hMemDC,
		ball.GetPos().x - ball.GetScale().x / 2,
		ball.GetPos().y - ball.GetScale().y / 2,
		ball.GetPos().x + ball.GetScale().x / 2,
		ball.GetPos().y + ball.GetScale().y / 2);

	RECT rc;
	rc.left = 0;
	rc.top = 0;
	rc.right = WINSIZEX;
	rc.bottom = WINSIZEY;
		

	if (true == IsStart)
	{
		if (ballPos.y >= rc.top + BALL_RADIUS / 2)
		{
			ballSpeed *= -1;
		}
		
		ballPos.y += ballSpeed;

		ball.SetPos(ballPos);
	}



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
	
	// 게임 윈도우의 DC 핸들값 가져오기
	m_hDC = GetDC(hWnd);	

	// 더블 버퍼링의 메모리 DC와 비트맵 생성
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	vaus = CGameObject(fPoint(600, 690), fPoint{ 150, 25 });
	ball = CGameObject(fPoint(600, 660), fPoint{ BALL_RADIUS, BALL_RADIUS });
}
