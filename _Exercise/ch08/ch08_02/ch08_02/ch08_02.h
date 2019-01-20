
// ch08_02.h : main header file for the ch08_02 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Cch0802App:
// See ch08_02.cpp for the implementation of this class
//

class Cch0802App : public CWinApp
{
public:
	Cch0802App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cch0802App theApp;
