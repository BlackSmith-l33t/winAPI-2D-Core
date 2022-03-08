#pragma once
class CUI;

class CUIManager
{
	SINGLETON(CUIManager);
private:
	CUI* m_pFoucedUI;

public:
	void update();

private:
	CUI* GetTargetUI(CUI* pParentUI);
	CUI* GetFoucedUI();
};

