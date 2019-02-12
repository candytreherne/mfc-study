
// UIThreadDemo.h : main header file for the UIThreadDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CUIThreadDemoApp:
// See UIThreadDemo.cpp for the implementation of this class
//

class CUIThreadDemoApp : public CWinApp
{
public:
	CUIThreadDemoApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CUIThreadDemoApp theApp;
