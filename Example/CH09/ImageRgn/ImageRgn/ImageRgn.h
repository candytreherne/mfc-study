
// ImageRgn.h : main header file for the ImageRgn application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CImageRgnApp:
// See ImageRgn.cpp for the implementation of this class
//

class CImageRgnApp : public CWinApp
{
public:
	CImageRgnApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CImageRgnApp theApp;
