#pragma once

class CCore 
{
	SINGLETON(CCore);
private:
	HDC		m_hDC;     // ������ DC �ڵ� : ���� ������ â�� �׸��� DC
	HDC		m_hMemDC;  // �޸� DC �ڵ� : �׸��� �۾��� �ӽ÷� ������ �޸��� DC
	HBITMAP m_hBMP;    // ��Ʈ�� �ڵ�    : �׸��� ���뿡 ���� �̹��� �ڵ�

	// GDI
	HBRUSH m_arrBrush[(int)TYPE_BRUSH::SIZE];
	HPEN m_arrPen[(int)TYPE_PEN::SIZE];

public:
	void update();
	void render();
	void init();

	HDC GetMainDC(); 
	
	void CreateBrushPen();
	HBRUSH GetBrush(TYPE_BRUSH brush);
	HPEN GetPen(TYPE_PEN pen);
};

