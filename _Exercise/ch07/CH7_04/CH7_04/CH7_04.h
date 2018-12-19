
// CH7_04.h : main header file for the CH7_04 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCH704App:
// See CH7_04.cpp for the implementation of this class
//

class CCH704App : public CWinApp
{
public:
	CCH704App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCH704App theApp;
