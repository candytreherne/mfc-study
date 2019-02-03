
// StaticDemo.h : main header file for the StaticDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CStaticDemoApp:
// See StaticDemo.cpp for the implementation of this class
//

class CStaticDemoApp : public CWinApp
{
public:
	CStaticDemoApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CStaticDemoApp theApp;
