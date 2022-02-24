#include "framework.h"
#include "CScene_Stage_01.h"
#include "CGameObject.h"
#include "CBall.h"
#include "CVaus.h"

CScene_Stage_01::CScene_Stage_01()
{
}

CScene_Stage_01::~CScene_Stage_01()
{
}

void CScene_Stage_01::Enter()
{
	// Vaus 持失
	CVaus* pVaus = new CVaus;
	pVaus->SetPos(fPoint(600, 690));
	AddObject(pVaus, GROUP_GAMEOBJ::PLAYER);	

	// Ball 持失

	CBall* pBall = new CBall;
	pBall->SetPos(fPoint(600, 660));
	AddObject(pBall, GROUP_GAMEOBJ::BALL);
}

void CScene_Stage_01::Exit()
{
	Clear();
}