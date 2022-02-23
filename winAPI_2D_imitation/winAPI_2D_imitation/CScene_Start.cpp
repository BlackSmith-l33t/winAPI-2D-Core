#include "framework.h"
#include "CScene_Start.h"
#include "CGameObject_MainText.h"

void CScene_Start::Enter()
{
	CGameObject_MainText* obj_Start = new CGameObject_MainText;
	obj_Start->SetPos(fPoint(450, 350));  // Text ��ġ 
	obj_Start->SetScale(fPoint(100, 100));
	obj_Start->SetText(L"�� ���� ������ ��������. �����̽��ٸ� ������.");

	AddObject(obj_Start, GROUP_GAMEOBJ::DEFAULT);
}

void CScene_Start::Exit()
{
	Clear();
}
