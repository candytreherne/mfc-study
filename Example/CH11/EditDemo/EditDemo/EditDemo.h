
// EditDemo.h : main header file for the EditDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CEditDemoApp:
// See EditDemo.cpp for the implementation of this class
//

class CEditDemoApp : public CWinApp
{
public:
	CEditDemoApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEditDemoApp theApp;
