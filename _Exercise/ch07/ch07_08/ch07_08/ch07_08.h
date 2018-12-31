
// ch07_08.h : main header file for the ch07_08 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cch0708App:
// See ch07_08.cpp for the implementation of this class
//

class Cch0708App : public CWinApp
{
public:
	Cch0708App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cch0708App theApp;
