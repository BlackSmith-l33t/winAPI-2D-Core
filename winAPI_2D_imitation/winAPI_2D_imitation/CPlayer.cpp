#include "framework.h"
#include "CPlayer.h"
#include "CMissile.h"
#include "CScene.h"
#include "CTexture.h"
#include "CCollider.h"
#include "CAnimator.h"
#include "CAnimation.h"

CPlayer::CPlayer()
{
	m_pTex = CResourceManager::getInst()->LoadTextrue(L"PlayerTex", L"texture\\Animation\\Player.bmp");
	SetName(L"Player");
	SetScale(fPoint(86.f, 80.f));

	CreateCollider();
	GetCollider()->SetScale(fPoint(20.f, 60.f));
	GetCollider()->SetOffsetPos(fPoint(0.f, 10.f));

	CreateAnimator();
	GetAnimator()->CreateAnimation(L"LeftNone",		m_pTex, fPoint(0.f, 0.f),	fPoint(86.f, 80.f), fPoint(0.f, 0.f), 0.5f, 1);
	GetAnimator()->CreateAnimation(L"RightNone",	m_pTex, fPoint(0.f, 86.f),	fPoint(86.f, 80.f), fPoint(70.f, 0.f), 0.5f, 2);
	GetAnimator()->CreateAnimation(L"LeftMove",		m_pTex, fPoint(0.f, 86.f),	fPoint(86.f, 80.f), fPoint(86.f, 0.f), 0.25f, 3);
	GetAnimator()->CreateAnimation(L"RightMove",	m_pTex, fPoint(0.f, 0.f), fPoint(86.f, 80.f), fPoint(86.f, 0.f), 0.25f, 5);
	GetAnimator()->CreateAnimation(L"LeftHit",		m_pTex, fPoint(140.f, 0.f), fPoint(86.f, 80.f), fPoint(70.f, 0.f), 0.25f, 1);
	GetAnimator()->CreateAnimation(L"RightHit",		m_pTex, fPoint(0.f, 172.f),fPoint(115.f, 100.f), fPoint(110.f, 0.f), 0.30f, 6);
	GetAnimator()->Play(L"LeftNone");

	// TODO : 캐릭터 주위에 보락색 테두리를 제거 해야함. 
	// TODO : 방향키를 누를 시에 계속 걷는 모션이 반복되는데 키가 눌려있는 순간에만 걷는 모션이 되게 해야함. 
	// TODO : space키를 누르면 미사일 발사 동시에 참격 액션을 취하는데 제대로 구현하지 못함.		

	CAnimation* pAni;
	pAni = GetAnimator()->FindAnimation(L"LeftMove");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, 0.f);
	pAni = GetAnimator()->FindAnimation(L"RightMove");
	pAni->GetFrame(1).fptOffset = fPoint(0.f, 0.f);
}

CPlayer::~CPlayer()
{

}

CPlayer* CPlayer::Clone()
{
	return new CPlayer(*this);
}

void CPlayer::update()
{
	fPoint pos = GetPos();

	if (Key(VK_LEFT))
	{
		pos.x -= m_fVelocity * fDT;
		GetAnimator()->Play(L"LeftMove");
	}
	if (Key(VK_RIGHT))
	{
		pos.x += m_fVelocity * fDT;
		GetAnimator()->Play(L"RightMove");
	}				   
	if (Key(VK_UP))	   
	{				   
		pos.y -= m_fVelocity * fDT;
	}				   
	if (Key(VK_DOWN))  
	{				   
		pos.y += m_fVelocity * fDT;
	}

	SetPos(pos);

	//if (KeyDown(VK_))

	if (KeyDown(VK_SPACE))
	{
		CreateMissile();
		GetAnimator()->Play(L"RightHit");
	}

	GetAnimator()->update();
}

void CPlayer::render(HDC hDC)
{
	component_render(hDC);
}

void CPlayer::CreateMissile()
{
 	fPoint fpMissilePos = GetPos();
	fpMissilePos.x += GetScale().x / 2.f;

	// Misiile Object
	CMissile* pMissile = new CMissile;
	pMissile->SetPos(fpMissilePos);
	pMissile->SetDir(fVec2(1, 0));

	CreateObj(pMissile, GROUP_GAMEOBJ::MISSILE_PLAYER);
}
