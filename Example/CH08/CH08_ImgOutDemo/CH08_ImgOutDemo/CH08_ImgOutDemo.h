
// CH08_ImgOutDemo.h : main header file for the CH08_ImgOutDemo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CCH08ImgOutDemoApp:
// See CH08_ImgOutDemo.cpp for the implementation of this class
//

class CCH08ImgOutDemoApp : public CWinApp
{
public:
	CCH08ImgOutDemoApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCH08ImgOutDemoApp theApp;
