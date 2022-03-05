#include "framework.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"

CPlayer::CPlayer()
{	m_pTex = CResourceManager::getInst()->LoadTexture(L"PlayerTex", L"texture\\Animation\\Animation_Player.bmp");
	SetName(L"Player");
	SetScale(fPoint(70.f, 70.f));
	
	CreateCollider();
	GetCollider()->SetScale(fPoint(40.f, 40.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 8.f));

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"LeftNone", m_pTex, fPoint(0.f, 0.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"RightNone", m_pTex, fPoint(0.f, 70.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"LeftMove", m_pTex, fPoint(0.f, 140.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"RightMove", m_pTex, fPoint(0.f, 210.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"LeftHit", m_pTex, fPoint(140.f, 0.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 1);
	GetAnimator()->CreateAnimation(L"RightHit", m_pTex, fPoint(140.f, 70.f), fPoint(70.f, 70.f), fPoint(70.f, 0.f), 0.25f, 1);
	GetAnimator()->Play(L"LeftNone");

	CAnimation* pAni;
	pAni = GetAnimator()->FindAnimation(L"LeftMove");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -20.f);
	pAni = GetAnimator()->FindAnimation(L"RightMove");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, -20.f);

}

CPlayer::~CPlayer()
{

}

CPlayer* CPlayer::Clone()
{
	return new CPlayer(*this);
}

void CPlayer::Update()
{
	fPoint pos = GetPos();

	if (KEY(VK_LEFT))
	{
		pos.x -= m_fVelocity * fDT;
		GetAnimator()->Play(L"LeftMove");
	}
	if (KEY(VK_RIGHT))
	{
		pos.x += m_fVelocity * fDT;
		GetAnimator()->Play(L"RightMove");
	}
	if (KEY(VK_UP))
	{
		pos.y -= m_fVelocity * fDT;
	}
	if (KEY(VK_DOWN))
	{
		pos.y += m_fVelocity * fDT;
	}

	SetPos(pos);

	if (KEYDOWN(VK_SPACE))
	{
		CreateMissile();
		GetAnimator()->Play(L"LeftHit");
	}

	GetAnimator()->update();
}

void CPlayer::Render(HDC hDC)
{
	int width = m_pTex->GetBMPWidth();
	int height = m_pTex->GetBMPHeight();

	fPoint pos = GetPos();

	Component_Render(hDC);
}

void CPlayer::CreateMissile()
{
	fPoint fptMissilePos = GetPos();
	fptMissilePos.x += GetScale().x / 2.f;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(fptMissilePos);
	pMissile->SetDir(fVec2(1, 0));

	CreateObj(pMissile, GROUP_GAMEOBJ::MISSILE_PLAYER);
	
}
