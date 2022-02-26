#pragma once
class CPathManager
{
	SINGLETON(CPathManager);

public:
	const static int MAXSIZE_PATH = 255;
private:
	WCHAR m_szContentPath[MAXSIZE_PATH];  // 리소스 경로를 저장

public:
	void init();

	const WCHAR* GetContentPath();
};

