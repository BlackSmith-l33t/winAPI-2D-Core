#include "framework.h"
#include "CScene_Start.h"
#include "CGameObject_MainText.h"

void CScene_Start::Enter()
{
	CGameObject_MainText* obj_Start = new CGameObject_MainText;
	obj_Start->SetPos(fPoint(450, 350));  // Text 위치 
	obj_Start->SetScale(fPoint(100, 100));
	obj_Start->SetText(L"자 이제 게임을 시작하지. 스페이스바를 누르렴.");

	AddObject(obj_Start, GROUP_GAMEOBJ::DEFAULT);
}

void CScene_Start::Exit()
{
	Clear();
}
