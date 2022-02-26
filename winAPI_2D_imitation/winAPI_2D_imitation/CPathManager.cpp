#include "framework.h"
#include "CPathManager.h"

CPathManager::CPathManager()
{
	m_szContentPath[0] = { };
}

CPathManager::~CPathManager()
{
}

void CPathManager::init()
{
	// 경로 : (게임 솔루션 경로) \Output\Debug
	// 경로 : (게임 솔루션 경로) \Output\Release
	GetCurrentDirectory(MAXSIZE_PATH, m_szContentPath); // 프로그램 경로를 확인하는 함수
	
	// 경로의 사이즈 구함
	int size = wcslen(m_szContentPath);

	for (int i = size - 1; i >= 0; i--)
	{
		// \\을 찾아서 \0으로 변경 : 첫번째 \\미만 삭제
		if ('\\' == m_szContentPath[i])
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}
	// 결로를 상위폴더로 이동 -> (게임 솔루션 경로) \Output

	// Release-> content 폴더에 있는 리소스로 접근
	wcscat_s(m_szContentPath, MAXSIZE_PATH, L"\\Release\\content\\");

	// TODO : Logger 추가 하기
}

const WCHAR* CPathManager::GetContentPath()
{
	return m_szContentPath;
}
