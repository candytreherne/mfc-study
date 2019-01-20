
// CH08_BmpDisplayDemo.h : main header file for the CH08_BmpDisplayDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCH08BmpDisplayDemoApp:
// See CH08_BmpDisplayDemo.cpp for the implementation of this class
//

class CCH08BmpDisplayDemoApp : public CWinApp
{
public:
	CCH08BmpDisplayDemoApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCH08BmpDisplayDemoApp theApp;
