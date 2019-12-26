//+-------------------------------------------------------------------------
//
//  dulib - DirectUI Library
//  Copyright (C) BodSoft
//
//  File:       duAnimation.h
//
//  History:    Nov-10-2009   Eric Qian  Created
//
//--------------------------------------------------------------------------
#pragma once

#include "duUtility.h"

#include "duPlugin.h"
#include "duTypes.h"

// duAnimation
//
// 
class duAnimation : public duPlugin
{
public:
	virtual void WINAPI RegisterControlProperty();
	virtual void WINAPI OnCreate();
	virtual void WINAPI DrawObject(HDC hDC);
	virtual LRESULT WINAPI OnWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	//virtual void WINAPI OnTimer(UINT nEventId);
	
	virtual void WINAPI Play();
	virtual void WINAPI StopPlay();

	//
	//��ȡ����ͼƬ������ͼƬ
	//
	virtual LPCTSTR WINAPI GetAnimation() { return m_szAnimation; }
	virtual void WINAPI SetAnimation(LPCTSTR lpszName);
	
	//
	//��ȡ���ٶȺ����ü��ٶ�
	//
	virtual int WINAPI GetAcceleration() { return m_nAcceleration; }
	virtual void WINAPI SetAcceleration(int nAcceleration) { m_nAcceleration=nAcceleration; }
	
	//
	//֡�������úͻ�ȡ
	//
	virtual int WINAPI GetFrameCount() { return m_nFrameCount; }
	virtual void WINAPI SetFrameCount(int nFrameCount) { m_nFrameCount=nFrameCount; }

	//
	//һ�����ڵ�ʱ�� û�а������ٶȵ�ʱ��
	//
	virtual int WINAPI GetTime() { return m_nTime; }
	virtual void WINAPI SetTime(int nTime) { m_nTime = nTime; }

	virtual void WINAPI FinalRelease() { delete this; }
	virtual LPCTSTR WINAPI GetTypeInfoName() { return _T("duAnimation"); }	
	
public:
	duAnimation();
	~duAnimation();
	
public:
	TCHAR m_szAnimation[MAX_NAME];
	int m_nAcceleration;
	int m_nFrameCount;
	int m_nTime;
	
	HANDLE m_hThread;
	HANDLE m_hTimerEvent;
	HANDLE m_hExitEvent;
	int m_nTimerId;
	int m_nCurFrame;
};
