
// ch08_04.h : main header file for the ch08_04 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cch0804App:
// See ch08_04.cpp for the implementation of this class
//

class Cch0804App : public CWinApp
{
public:
	Cch0804App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cch0804App theApp;
