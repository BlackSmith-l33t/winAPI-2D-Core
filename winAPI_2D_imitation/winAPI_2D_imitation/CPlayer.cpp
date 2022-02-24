#include "framework.h"
#include "CPlayer.h"
#include "framework.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"
CPlayer::CPlayer()
{
	SetScale(fPoint(50, 50));

}

CPlayer::~CPlayer()
{

}

void CPlayer::Update()
{
	fPoint pos = GetPos();
	if (KEY(VK_LEFT))
	{
		pos.x -= m_dVelocity * DT;
	}

	if (KEY(VK_RIGHT))
	{
		pos.x += m_dVelocity * DT;
	}

	if (KEY(VK_UP))
	{
		pos.y -= m_dVelocity * DT;
	}

	if (KEY(VK_DOWN))
	{
		pos.y += m_dVelocity * DT;
	}

	SetPos(pos);

	if (CKeyManager::getInst()->GetButtonDown(VK_SPACE))
	{
		CreateMissile();
	}
}

void CPlayer::Render(HDC hDC)
{
	Rectangle(hDC,
		(int)(GetPos().x - GetScale().x / 2),
		(int)(GetPos().y - GetScale().y / 2),
		(int)(GetPos().x + GetScale().x / 2),
		(int)(GetPos().y + GetScale().y / 2)
	);
}

void CPlayer::CreateMissile()
{
	fPoint fptMissilePos = GetPos();
	fptMissilePos.x += GetScale().x / 2.f;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(fptMissilePos);
	pMissile->SetDir(fVec2(1, 0));

	CScene* pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_GAMEOBJ::MISSILE);

	CMissile* pMissile2 = new CMissile;
	pMissile2->SetPos(fptMissilePos);
	pMissile2->SetDir(fVec2(0, 1));

	pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile2, GROUP_GAMEOBJ::MISSILE);

	CMissile* pMissile3 = new CMissile;
	pMissile3->SetPos(fptMissilePos);
	pMissile3->SetDir(fVec2(0, -1));

	pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile3, GROUP_GAMEOBJ::MISSILE);

	CMissile* pMissile4 = new CMissile;
	pMissile4->SetPos(fptMissilePos);
	pMissile4->SetDir(fVec2(1, -1));

	pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile4, GROUP_GAMEOBJ::MISSILE);

	CMissile* pMissile5 = new CMissile;
	pMissile5->SetPos(fptMissilePos);
	pMissile5->SetDir(fVec2(1, 1));

	pCurScene = CSceneManager::getInst()->GetCurScene();
	pCurScene->AddObject(pMissile5, GROUP_GAMEOBJ::MISSILE);
}
