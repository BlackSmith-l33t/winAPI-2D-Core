#pragma once
class CPathManager
{
	SINGLETON(CPathManager);

public:
	const static int MAXSIZE_PATH = 255;
private:
	WCHAR m_szContentPath[MAXSIZE_PATH];  // ���ҽ� ��θ� ����

public:
	void init();

	const WCHAR* GetContentPath();
};

