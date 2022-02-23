// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.
//

#pragma once

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
using std::string;
using std::wstring;

//STL
#include <vector>
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
	BRICK_BREAKER, // 지금 만들고 있는 게임을 한 그룹으로 분류
	PLAYER,
	MONSTER,
	MISSILE,

	SIZE,
};

// Util
#include "SingleTon.h"
#include "struct.h"
#include "CCore.h"
#include "CTimeManager.h"
#include "CKeyManager.h"
#include "CSceneManager.h"

// 디파인문

#define WINSTARTX	300
#define WINSTARTY	150
#define WINSIZEX	1280
#define WINSIZEY	720
#define WINSTYLE	WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX


#define DT					CTimeManager::getInst()->GetDT();
#define KEY(vk_key)			CKeyManager::getInst()->GetButton(vk_key)
#define KEYDOWN(vk_key)		CKeyManager::getInst()->GetButtonDown(vk_key)
#define KEYUP(vk_key)		CKeyManager::getInst()->GetButtonUp(vk_key)

#define BALL_RADIUS 15
#define VAUSX 150
#define VAUSY 25


// 전역 변수 : 인스턴스, 윈도우 핸들
extern HINSTANCE hInst;
extern HWND hWnd;

