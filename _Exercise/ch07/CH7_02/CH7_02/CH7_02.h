
// CH7_02.h : main header file for the CH7_02 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCH702App:
// See CH7_02.cpp for the implementation of this class
//

class CCH702App : public CWinApp
{
public:
	CCH702App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCH702App theApp;
