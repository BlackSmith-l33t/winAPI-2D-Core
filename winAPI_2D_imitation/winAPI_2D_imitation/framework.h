// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once
#pragma comment(lib, "Msimg32.lib")

#include "targetver.h"
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
// Windows 헤더 파일
#include <windows.h>
// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string>
#include <assert.h>
using std::string;
using std::wstring;

//STL
#include <vector>
#include <map>
using namespace std;
using std::vector;

// 씬 그룹
enum class GROUP_SCENE
{
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

	SIZE,
};

// 오브젝트 그룹
enum class GROUP_GAMEOBJ
{
	DEFAULT,
	PLAYER,
	MONSTER,
	MISSILE_PLAYER,
	MISSILE_MONSTER,

	SIZE,
};

// Core DC : GDI 그룹 
enum class TYPE_PEN
{
	RED,
	GREEN,
	BLUE,

	SIZE,
};

enum class TYPE_BRUSH
{
	HOLLOW,

	SIZE,
};

// 이벤트 타입
enum class TYPE_EVENT
{
	CREATE_OBJECT,
	DELETE_OBJECT,
	CHANGE_SCENE,

	SIZE,
};


// Util
#include "SingleTon.h"
#include "struct.h"
#include "CCore.h"

#include "CResourceManager.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"
#include "CPathManager.h"
#include "CCollisionManager.h"
#include "CEventManager.h"

// 디파인문

#define WINSTARTX	100
#define WINSTARTY	100
#define WINSIZEX	1280
#define WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

#define DT					CTimeManager::getInst()->GetDT();
#define fDT					CTimeManager::getInst()->GetfDT();

#define KEY(vk_key)			CKeyManager::getInst()->GetButton(vk_key)
#define KEYDOWN(vk_key)		CKeyManager::getInst()->GetButtonDown(vk_key)
#define KEYUP(vk_key)		CKeyManager::getInst()->GetButtonUp(vk_key)

#define CreateObj(pObj, group)	CEventManager::getInst()->EventCreateObject(pObj, group)
#define DeleteObj(pObj)			CEventManager::getInst()->EventDeleteObject(pObj)
#define ChangeScn(scene)		CEventManager::getInst()->EventChangeScene(scene)

// 전역 변수 : 인스턴스, 윈도우 핸들
extern HINSTANCE hInst;
extern HWND hWnd;

