//+-------------------------------------------------------------------------
//
//  dulib - DirectUI Library
//  Copyright (C) BodSoft
//
//  File:       duLayout.h
//
//  History:    JAN-09-2010   Denny Chen  Created
//
//--------------------------------------------------------------------------
#pragma once

#include "duUtility.h"
#include "duPlugin.h"
#include "duTypes.h"

#define LAYOUT_NORMAL				 0 // ���ù����Ӷ���
#define LAYOUT_LEFTTORIGHT			 1 // ���Ӷ������������
#define LAYOUT_RIGHTTOLEFT			 2 // ���Ӷ�����ҵ�������
#define LAYOUT_TOPTOBOTTOM			 3 // ���Ӷ�����ϵ�������
#define LAYOUT_BOTTOMTOTOP			 4 // ���Ӷ�����µ�������
#define LAYOUT_HORZ_BRIMMING		 5 // ���Ӷ���ˮƽ���� �Ӷ����� = Layout��� / �Ӷ�������
#define LAYOUT_VERT_BRIMMING		 6 // ���Ӷ���ֱ���� �Ӷ���߶� = Layout�߶� / �Ӷ�������
#define LAYOUT_GRID					 7 // ���Ӷ����б������


class duLayout : public duPlugin
{
public:
	virtual void WINAPI RegisterControlProperty();
	virtual void WINAPI OnCreate();
	virtual void WINAPI DrawObject(HDC hDC);
	virtual void WINAPI Resize(LPRECT lpRect);
	
	virtual void WINAPI OnChildShow(duPlugin *pChild, BOOL fVisible);
	virtual void WINAPI OnChildResize(duPlugin *pChild);
	virtual LRESULT WINAPI OnWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	virtual int WINAPI GetLayoutType() { return m_nLayoutType; }
	virtual void WINAPI SetLayoutType(int nLayoutType) { m_nLayoutType = nLayoutType; }

	virtual int WINAPI GetStartX() { return m_nStartX; }
	virtual void WINAPI SetStartX(int nStartX) { m_nStartX = nStartX; }

	virtual int WINAPI GetStartY() { return m_nStartY; }
	virtual void WINAPI SetStartY(int nStartY) { m_nStartY = nStartY; }

	virtual int WINAPI GetXSpace() { return m_nXSpace; }
	virtual void WINAPI SetXSpace(int nXSpace) { m_nXSpace = nXSpace; }

	virtual int  WINAPI GetYSpace() { return m_nYSpace; }
	virtual void WINAPI SetYSpace(int nYSpace) { m_nYSpace = nYSpace; }

	virtual void WINAPI AdjustChilds();

	virtual BOOL WINAPI IsAlwaysHot() { return m_fAlwaysHot; }
	virtual void WINAPI SetAlwaysHot(BOOL fAlwaysHot);

	virtual void WINAPI FinalRelease() { delete this; }
	virtual LPCTSTR WINAPI GetTypeInfoName() { return _T("duLayout"); }	

public:
	duLayout();
	~duLayout();
	
public:
	void WINAPI AdjustLeftRight();
	void WINAPI AdjustRightLeft();
	void WINAPI AdjustTopBottom();
	void WINAPI AdjustBottomTop();
	void WINAPI AdjustHorzBrimming();
	void WINAPI AdjustVertBrimming();
	void WINAPI AdjustGrid();

protected:
	UINT m_nLayoutType;
	int m_nStartX;
	int m_nStartY;
	int m_nXSpace;
	int m_nYSpace;
	BOOL m_fAlwaysHot;
};

duPlugin *WINAPI GetPreVisible(duPlugin *pPlugin);
duPlugin *WINAPI GetNextVisible(duPlugin *pPlugin);
int WINAPI GetVisibleChildCount(duPlugin *pPlugin);
