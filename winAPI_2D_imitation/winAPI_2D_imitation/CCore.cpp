#include "framework.h"
#include "CCore.h"
#include "CGameObject.h"
#include "CScene.h"
#include "CBall.h"

CScene scene_stage1;
CBall* ball = new CBall;

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

	delete ball;
}

void CCore::update()
{
	CTimeManager::getInst()->update();
	CKeyManager::getInst()->Update();
	
	// ���� ���� ���� ����
	// GetAsyncKeyState : �޽��� ť�� Ű �Է��� �޴� ����� �ƴ�  ���� ������ Ű �Է»��¸� Ȯ��
	if (KEY(VK_SPACE))
	{
		ball->IsStart = true;
	}
}

void CCore::render()
{
	// ���� ������ ��뵵 memDC�� �׸��� �۾� ����
	Rectangle(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);
	//Ellipse(m_hMemDC, -1, -1, WINSIZEX + 1, WINSIZEY + 1);

	scene_stage1.Render(m_hMemDC);

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
	CTimeManager::getInst()->Init();
	CKeyManager::getInst()->Init();
	
	// ���� �������� DC �ڵ鰪 ��������
	m_hDC = GetDC(hWnd);	

	// ���� ���۸��� �޸� DC�� ��Ʈ�� ����
	m_hMemDC = CreateCompatibleDC(m_hDC);
	m_hBMP = CreateCompatibleBitmap(m_hDC, WINSIZEX, WINSIZEY);

	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hMemDC, m_hBMP);
	DeleteObject(hOldBitmap);

	/*CGameObject* vaus = new CGameObject;
	vaus->SetPos(fPoint(600, 690));
	vaus->SetScale(fPoint{ VAUSX, VAUSY });
	scene_stage1.AddObject(vaus, GROUP_GAMEOBJ::BRICK_BREAKER);*/
		
	ball->SetPos(fPoint(600, 660));
	ball->SetScale(fPoint{ BALL_RADIUS, BALL_RADIUS });
	scene_stage1.AddObject(ball, GROUP_GAMEOBJ::BRICK_BREAKER);

	// TODO : ���� �����ϱ�	
}
  