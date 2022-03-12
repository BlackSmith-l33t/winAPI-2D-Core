#pragma once

class CTexture;
class CSound;

class CResourceManager
{
	SINGLETON(CResourceManager);

private:
	map<wstring, CTexture*> m_mapTex;		// Texture ���ҽ��� ���� �ڷᱸ��
	map<wstring, CSound*> m_mapSound;
	CSound* m_pBGM;

public:
	CTexture* FindTexture(const wstring& strKey);	// ����� Texture Ž��
	CTexture* LoadTextrue(const wstring& strKey, const wstring& strRelativePath);	// Texture �ҷ����� �̹� �ִ� ��� �ִ� Texture ��ȯ
	CTexture* CreateTexture(const wstring& strKey, UINT width, UINT height);

	CSound* FindSound(const wstring& strKey);  // 8�� ���� 8�� 27��
	CSound* LoadSound(const wstring& strKey, const wstring& strRelativePath);
};

