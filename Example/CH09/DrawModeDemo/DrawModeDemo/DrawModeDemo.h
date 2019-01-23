
// DrawModeDemo.h : main header file for the DrawModeDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CDrawModeDemoApp:
// See DrawModeDemo.cpp for the implementation of this class
//

class CDrawModeDemoApp : public CWinApp
{
public:
	CDrawModeDemoApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDrawModeDemoApp theApp;
