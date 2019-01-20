
// ch08_03.h : main header file for the ch08_03 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cch0803App:
// See ch08_03.cpp for the implementation of this class
//

class Cch0803App : public CWinApp
{
public:
	Cch0803App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cch0803App theApp;
