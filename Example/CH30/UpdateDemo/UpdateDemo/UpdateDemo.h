
// UpdateDemo.h : main header file for the UpdateDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CUpdateDemoApp:
// See UpdateDemo.cpp for the implementation of this class
//

class CUpdateDemoApp : public CWinApp
{
public:
	CUpdateDemoApp() noexcept;

	CEvent m_ExitEvent;
	CEvent m_UpdateEvent;

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	static UINT ThreadUpdate(LPVOID pParam);
};

extern CUpdateDemoApp theApp;
