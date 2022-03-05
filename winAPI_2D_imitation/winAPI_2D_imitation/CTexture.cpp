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
		nullptr,								// hInstance, nulltptr로 유지
		strFilePath.c_str(),					// 파일의 경로, C Style의 문자열 
		IMAGE_BITMAP,							// 이미지 타입, 비트맵 이미지로 지정
		0, 0,									// 이미지의 XY 크기, 0을 주면 자동으로 이미지크기 설정
		LR_CREATEDIBSECTION | LR_LOADFROMFILE); // 이미지의 속성

	if (0 == m_hBMP)
	{
		assert(nullptr);
	}

	// 비트맵을 가지고 BMPInfo
	m_hDC = CreateCompatibleDC(CCore::getInst()->GetMainDC());

	// 비트맵과 DC 연결
	HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hDC, m_hBMP);

	// 비트맵 Info 추출
	GetObject(m_hBMP, sizeof(BITMAP), &m_bmpInfo);
}
