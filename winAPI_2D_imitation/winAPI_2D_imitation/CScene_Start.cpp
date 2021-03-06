#include "framework.h"
#include "CScene_Start.h"
#include "CGameObject.h"
#include "CPlayer.h"
#include "CMonster.h"
#include "CMissile.h"

CScene_Start::CScene_Start()
{
}

CScene_Start::~CScene_Start()
{
}

void CScene_Start::Enter()
{
	// player ?߰?

	CPlayer* pPlayer = new CPlayer;

	pPlayer->SetPos(fPoint(500, 100));

	AddObject(pPlayer, GROUP_GAMEOBJ::PLAYER);

	// monster ?߰?
	CMonster* pMonster = new CMonster;
	pMonster->SetPos(fPoint(1100, 350));
	pMonster->SetCenterPos(pMonster->GetPos());
	AddObject(pMonster, GROUP_GAMEOBJ::MONSTER);
}

void CScene_Start::Exit()
{
	Clear();
}
