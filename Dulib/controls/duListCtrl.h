//+-------------------------------------------------------------------------
//
//  dulib - DirectUI Library
//  Copyright (C) BodSoft
//
//  File:       duListCtrl.h
//
//  History:    Nov-10-2009   Eric Qian  Created
//
//--------------------------------------------------------------------------
#pragma once

#include "duUtility.h"
#include "duPlugin.h"
#include "duTypes.h"
#include "duScrollView.h"

// duListCtrl
// 
// 
class duListCtrl : public duScrollView
{
public:
	virtual void WINAPI RegisterControlProperty();
	virtual void WINAPI OnCreate();
	virtual void WINAPI DrawObject(HDC hDC);
	virtual void WINAPI GetViewSize(LPSIZE lpSize);
	virtual void WINAPI OnVScroll(ScrollBarAction sbAction, int nPos);
	virtual void WINAPI OnHScroll(ScrollBarAction sbAction, int nPos);
	virtual LRESULT WINAPI OnWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	virtual void WINAPI Resize(LPRECT lpRect/*=NULL*/);
	
	virtual duPlugin *WINAPI InsertLine(int nIndex, LPCTSTR lpszTemplate);
	virtual duPlugin *WINAPI GetLine(int nIndex);
	virtual int WINAPI GetLineCount();
	virtual int WINAPI GetTotalHeight();
	virtual duPlugin *WINAPI GetFirstVisibleLine();
	virtual BOOL WINAPI MoveLine(int nIndex, int nNewIndex);
	virtual BOOL WINAPI DeleteLine(int nIndex, BOOL fAdjust);
	virtual void WINAPI ResetLine();

	virtual void WINAPI VertScroll(int nPos);
	virtual void WINAPI HorzScroll(int nPos);
	virtual void WINAPI AdjustColumn();
	virtual void WINAPI AdjustColumnWidth(int nCol, int nWidth);
	virtual int WINAPI GetSel();
	virtual void WINAPI SetSel(int nSel);

	virtual LPCTSTR WINAPI GetHeaderCtrl() { return m_szHeaderCtrl; }
	virtual void WINAPI SetHeaderCtrl(LPCTSTR lpszHeader);
	
	virtual void WINAPI FinalRelease() { delete this; }
	virtual LPCTSTR WINAPI GetTypeInfoName() { return _T("duListCtrl"); }

public:
	duListCtrl();
	~duListCtrl();
	
protected:
	void AdjustVisibleLine(int nTop);
	void CompleteAdjustLine();
	int GetLinePluginIndex(duPlugin *pPlugin);

protected:
	int m_nCloneIndex;
	duPlugin *m_pSel;
	duPlugin *m_pHot;

protected:
	int m_nHotLine;					// ��������
	int m_nFirstLine;				// ��ʾ�����һ��
	int m_nFLTotalHeight;			// ��ʾ����ǰ�������иߵ��ܺ�
	int m_nViewCy;					// ��ͼ�߶�
	TCHAR m_szHeaderCtrl[MAX_NAME]; 
	vector<duPlugin *> m_vtLines;
	BOOL m_fDispMouseWheel;
};
