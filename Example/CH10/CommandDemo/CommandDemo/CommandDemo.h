
// CommandDemo.h : main header file for the CommandDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCommandDemoApp:
// See CommandDemo.cpp for the implementation of this class
//

class CCommandDemoApp : public CWinApp
{
public:
	CCommandDemoApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCommandDemoApp theApp;
