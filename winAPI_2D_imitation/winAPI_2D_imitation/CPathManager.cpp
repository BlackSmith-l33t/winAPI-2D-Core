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
	// ��� : (���� �ַ�� ���) \Output\Debug
	// ��� : (���� �ַ�� ���) \Output\Release
	GetCurrentDirectory(MAXSIZE_PATH, m_szContentPath); // ���α׷� ��θ� Ȯ���ϴ� �Լ�
	
	// ����� ������ ����
	int size = wcslen(m_szContentPath);

	for (int i = size - 1; i >= 0; i--)
	{
		// \\�� ã�Ƽ� \0���� ���� : ù��° \\�̸� ����
		if ('\\' == m_szContentPath[i])
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}
	// ��θ� ���������� �̵� -> (���� �ַ�� ���) \Output

	// Release-> content ������ �ִ� ���ҽ��� ����
	wcscat_s(m_szContentPath, MAXSIZE_PATH, L"\\Release\\content\\");

	// TODO : Logger �߰� �ϱ�
}

const WCHAR* CPathManager::GetContentPath()
{
	return m_szContentPath;
}
