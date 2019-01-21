
// TextRgn.h : main header file for the TextRgn application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTextRgnApp:
// See TextRgn.cpp for the implementation of this class
//

class CTextRgnApp : public CWinApp
{
public:
	CTextRgnApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTextRgnApp theApp;
