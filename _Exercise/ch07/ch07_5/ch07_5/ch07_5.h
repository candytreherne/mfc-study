
// ch07_5.h : main header file for the ch07_5 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cch075App:
// See ch07_5.cpp for the implementation of this class
//

class Cch075App : public CWinApp
{
public:
	Cch075App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cch075App theApp;
