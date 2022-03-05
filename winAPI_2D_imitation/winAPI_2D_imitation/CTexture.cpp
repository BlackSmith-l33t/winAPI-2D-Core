#include "framework.h"
#include "CTexture.h"

CTexture::CTexture()
{
	m_hDC = 0;
	m_hBMP = 0;
	m_bmpInfo = { };
}

CTexture::~CTexture()
{
	DeleteDC(m_hDC);
	DeleteObject(m_hBMP);
}

HDC CTexture::GetDC()
{
	return m_hDC;
}

HBITMAP CTexture::GetBitmap()
{
	return m_hBMP;
}

BITMAP CTexture::GetBitInfo()
{
	return m_bmpInfo;
}

int CTexture::GetBMPWidth()
{
	return (int)m_bmpInfo.bmWidth;
}

int CTexture::GetBMPHeight()
{
	return (int)m_bmpInfo.bmHeight;
}

void CTexture::Load(const wstring& strFilePath)
{
	m_hBMP = (HBITMAP)LoadImage(
		nullptr,								// hInstance, nulltptr�� ����
		strFilePath.c_str(),					// ������ ���, C Style�� ���ڿ� 
		IMAGE_BITMAP,							// �̹��� Ÿ��, ��Ʈ�� �̹����� ����
		0, 0,									// �̹����� XY ũ��, 0�� �ָ� �ڵ����� �̹���ũ�� ����
		LR_CREATEDIBSECTION | LR_LOADFROMFILE); // �̹����� �Ӽ�

	if (0 == m_hBMP)
	{
		assert(nullptr);
	}

	// ��Ʈ���� ������ BMPInfo
	m_hDC = CreateCompatibleDC(CCore::getInst()->GetMainDC());

	// ��Ʈ�ʰ� DC ����
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hDC, m_hBMP);

	// ��Ʈ�� Info ����
	GetObject(m_hBMP, sizeof(BITMAP), &m_bmpInfo);
}
