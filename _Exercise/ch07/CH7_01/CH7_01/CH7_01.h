
// CH7_01.h : main header file for the CH7_01 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCH701App:
// See CH7_01.cpp for the implementation of this class
//

class CCH701App : public CWinApp
{
public:
	CCH701App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCH701App theApp;
