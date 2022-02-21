#include "framework.h"
#include "CKeyManager.h"

CKeyManager::CKeyManager()
{
	// Ű ���¸� ��� ������ ���� ���·� �ʱ�ȭ
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = false;
		m_arrCurKey[key] = false;
	}
}

CKeyManager::~CKeyManager()
{

}

void CKeyManager::Update()
{
	// ���� ����(Focus)�� �����찡 ���� �������ΰ��� Ȯ��
	HWND curWnd = GetFocus();
	// ���� ���� �����찡 ���õ� �����찡 �ƴ� ���
	if (hWnd != curWnd)
	{
		//  �����찡 ���õ� ���°� �ƴ� ��� Ű�Է��� ��� false(����) ��Ŵ
		for (int key = 0; key < VKEY_SIZE; key++)
		{
			m_arrPrevKey[key] = m_arrCurKey[key];
			m_arrCurKey[key] = false;
		}
		return;
	}
	// ��� Ű �����ŭ �ݺ��ϸ鼭 �� Ű�� �Է� ���¸� Ȯ��
	for (int key = 0; key < VKEY_SIZE; key++)
	{
		m_arrPrevKey[key] = m_arrCurKey[key];
		if (GetAsyncKeyState(key) & 0x8000)
		{
			m_arrCurKey[key] = true;
		}
		else
		{
			m_arrCurKey[key] = false;
		}
	}
}

void CKeyManager::Init()
{
}

bool CKeyManager::GetButton(const int key)
{
	return (true == m_arrPrevKey[key] && true == m_arrCurKey[key]);
}

bool CKeyManager::GetButtonDown(const int key)
{
	return (false == m_arrPrevKey[key] && true == m_arrCurKey[key]);
}

bool CKeyManager::GetButtonUp(const int key)
{
	return (true == m_arrPrevKey[key] && false == m_arrCurKey[key]);
}
