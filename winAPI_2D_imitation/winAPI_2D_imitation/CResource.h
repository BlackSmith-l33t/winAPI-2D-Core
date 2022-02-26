#pragma once
class CResource
{	
private:
	wstring m_strPath;
	wstring m_strKey;
public:
	CResource();
	virtual ~CResource();

	void SetKey(const wstring& strKey);
	const wstring& GetKey();

	void SetPath(const wstring& strPath);
	const wstring& GetPath();
};

