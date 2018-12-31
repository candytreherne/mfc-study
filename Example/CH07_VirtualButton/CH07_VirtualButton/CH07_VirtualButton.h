
// CH07_VirtualButton.h : main header file for the CH07_VirtualButton application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCH07VirtualButtonApp:
// See CH07_VirtualButton.cpp for the implementation of this class
//

class CCH07VirtualButtonApp : public CWinApp
{
public:
	CCH07VirtualButtonApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCH07VirtualButtonApp theApp;
