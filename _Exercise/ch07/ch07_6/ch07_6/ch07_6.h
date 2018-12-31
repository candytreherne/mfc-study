
// ch07_6.h : main header file for the ch07_6 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cch076App:
// See ch07_6.cpp for the implementation of this class
//

class Cch076App : public CWinApp
{
public:
	Cch076App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cch076App theApp;
