#pragma once
class CKeyManager
{
	SINGLETON(CKeyManager);
private:
	static const int VKEY_SIZE = 0xFF;	// VK의 최대 갯수

	bool m_arrPrevKey[VKEY_SIZE];		// 이전 키의 입력상태를 저장할 배열
	bool m_arrCurKey[VKEY_SIZE];		// 현재 키의 입력상태를 저장할 배열
public:
	void Update();
	void Init();

	bool GetButton(const int key);		// 키가 눌려진 상태 true
	bool GetButtonDown(const int key);  // 키가 눌려진 순간만 true;
	bool GetButtonUp(const int key);	// 키가 올라간 순간만 true;
};

