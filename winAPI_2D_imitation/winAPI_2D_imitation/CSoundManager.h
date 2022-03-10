#pragma once
#include "FMOD/inc/fmod.hpp"
#pragma comment(lib, "FMOD/lib/fmod_vc.lib")

using namespace FMOD;
class CSound;
class CSoundManager
{
	SINGLETON(CSoundManager);

private:
	map<wstring, CSound*> m_mapSound;  // ������� �����ϱ� ���� �ڷᱸ��
	System* m_pSystem;					// ���� �ý���

public:
	void init();
	void update();

	System* GetSystem();

	void AddSound(wstring keName, wstring filePath, bool bgm);

	void Play(wstring keyName);
	void Stop(wstring keyName);
	void Pause(wstring keyName);
	void Resume(wstring keyName);

	bool IsPlaySound(wstring keyName);
	bool IsPauseSound(wstring keyName);
};

