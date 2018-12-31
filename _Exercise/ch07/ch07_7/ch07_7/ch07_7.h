
// ch07_7.h : main header file for the ch07_7 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cch077App:
// See ch07_7.cpp for the implementation of this class
//

class Cch077App : public CWinApp
{
public:
	Cch077App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cch077App theApp;
