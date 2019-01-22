
// FrameRgn.h : main header file for the FrameRgn application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CFrameRgnApp:
// See FrameRgn.cpp for the implementation of this class
//

class CFrameRgnApp : public CWinApp
{
public:
	CFrameRgnApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CFrameRgnApp theApp;
