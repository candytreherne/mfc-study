
// SaveGrayDemo.h : main header file for the SaveGrayDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CSaveGrayDemoApp:
// See SaveGrayDemo.cpp for the implementation of this class
//

class CSaveGrayDemoApp : public CWinApp
{
public:
	CSaveGrayDemoApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CSaveGrayDemoApp theApp;
