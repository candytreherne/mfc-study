
// ch08_01.h : main header file for the ch08_01 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cch0801App:
// See ch08_01.cpp for the implementation of this class
//

class Cch0801App : public CWinApp
{
public:
	Cch0801App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cch0801App theApp;
