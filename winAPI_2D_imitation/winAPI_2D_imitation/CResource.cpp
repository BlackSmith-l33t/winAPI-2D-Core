#include "framework.h"
#include "CResource.h"

CResource::CResource()
{
	m_strKey = {};
	m_strPath = {};
}

CResource::~CResource()
{
}

void CResource::SetKey(const wstring& strKey)
{
	m_strKey = strKey;
}

const wstring& CResource::GetKey()
{
	return m_strKey;
}

void CResource::SetPath(const wstring& strPath)
{
	m_strPath = strPath;
}

const wstring& CResource::GetPath()
{
	return m_strPath;
}
