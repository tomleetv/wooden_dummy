#pragma once
#include "KWindow.h"
#include "KTimer.h"
#include "KInput.h"
class KCore : public KWindow
{
public:
	KTimer		m_Timer;
	KInput		m_Input;
	HDC			m_hScreenDC;   // 전면 버퍼
	HBITMAP		m_hOldBitmap; // 후면버퍼의 이미지

	HDC			m_hOffScreenDC;// 후면 버퍼
	HBITMAP		m_hOffScreenBitmap; // 후면버퍼의 이미지	

	HBRUSH		m_hbrBack;
	HBRUSH		m_hbrOld;

	HFONT		m_fontDefault;
	HFONT		m_fontDefaultOld;
public:
	bool	GameRun();
	bool	GameInit();	
	bool	GameFrame();
	bool	GameRender();
	bool    GameRelease();
	void	MsgEvent(MSG msg);

	virtual bool	DrawDebug();
	virtual bool    DrawDebug(TCHAR* pString, int iX, int iY);
	virtual bool	PreRender();
	virtual bool	PostRender();
public:
	////////// 가상 함수들 ///////////
	virtual bool		Init() { return true; }
	virtual bool		PreFrame() { return true; }	
	virtual bool		PostFrame() { return true; }	
	virtual bool		Frame() { return true; }
	virtual bool		Render() { return true; }
	virtual bool		Release() { return true; };
public:
	KCore();
	virtual ~KCore();
};

