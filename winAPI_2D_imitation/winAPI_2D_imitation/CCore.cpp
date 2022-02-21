#include "framework.h"
#include "CCore.h"
#include "CGameObject.h"

// CCore* CCore::_instance = NULL;
#define BALL_RADIUS 15

CGameObject vaus;  // TODO : �ٿ콺�� ����ֱ�
CGameObject ball;  // TODO : ���� ����ֱ�
fPoint vausPos;
fPoint ballPos;

bool IsStart = false;

CCore::CCore()
{
	// ���� ȭ���� �׸��� ���� DC �ڵ鰪 �ʱ�ȭ
	m_hDC = 0;	
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
	vausPos = vaus.GetPos();
	ballPos = ball.GetPos();

	// ���� ���� ���� ����
	// GetAsyncKeyState : �޽��� ť�� Ű �Է��� �޴� ����� �ƴ�  ���� ������ Ű �Է»��¸� Ȯ��
	if (GetAsyncKeyState(VK_LEFT) & 0x8000) // �ش� Ű�� �����ִ��� Ȯ���ϴ� �ڵ�
	{
		vausPos.x -= 500 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		vausPos.x += 500 * CTimeManager::getInst()->GetDT();
	}

	if (GetAsyncKeyState(VK_SPACE) & 0x8000) // Space�� ������ ������ ���۵�.
	{
		IsStart = true;
	}

	vaus.SetPos(vausPos);
	ball.SetPos(ballPos);
}

void CCore::render()
{	
	// ���� ������ ��뵵 memDC�� �׸��� �۾� ����
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
			// TODO : �Ϸ��� �ϴ� �� -> window â ����鿡 ��ܿ� ���� ���� �ÿ� �ǵ��ƿ��� ���� �����ϰ� �ִ� ��
			// �߰� �ڷῡ ��ħ ��ī���̵� ���� ������ �־ �����ϴ� ��.
	
		}
		
		ballPos.y += ballSpeed;

		ball.SetPos(ballPos);
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
	
	// ���� �������� DC �ڵ鰪 ��������
	m_hDC = GetDC(hWnd);	

	// ���� ���۸��� �޸� DC�� ��Ʈ�� ����
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	vaus = CGameObject(fPoint(600, 690), fPoint{ 150, 25 });
	ball = CGameObject(fPoint(600, 660), fPoint{ BALL_RADIUS, BALL_RADIUS });
}
