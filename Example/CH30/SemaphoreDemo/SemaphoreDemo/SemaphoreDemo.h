
// SemaphoreDemo.h : main header file for the SemaphoreDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSemaphoreDemoApp:
// See SemaphoreDemo.cpp for the implementation of this class
//

class CSemaphoreDemoApp : public CWinApp
{
public:
	CSemaphoreDemoApp() noexcept;

	CEvent m_ExitEvent;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	static UINT ThreadSemaphore(LPVOID pParam);
};

extern CSemaphoreDemoApp theApp;
