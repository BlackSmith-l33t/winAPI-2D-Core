#include "framework.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"

CPlayer::CPlayer()
{	m_pTex = CResourceManager::getInst()->LoadTexture(L"PlayerTex", L"texture\\Player.bmp");
	CreateCollider();
	GetCollider()->SetScale(fPoint(40.f, 40.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 8.f));
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
	int width = m_pTex->GetBMPWidth();
	int height = m_pTex->GetBMPHeight();

	TransparentBlt(hDC,
		GetPos().x - width / 2.f,
		GetPos().y - height / 2.f,
		width, height,
		m_pTex->GetDC(),
		0, 0, width, height,
		RGB(255, 0, 255));

	Component_Render(hDC);
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
	
}
