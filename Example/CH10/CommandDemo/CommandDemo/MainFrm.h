
// MainFrm.h : interface of the CMainFrame class
//

#pragma once

class CMainFrame : public CFrameWnd
{
	
protected: // create from serialization only
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)

// Attributes
public:
	BOOL m_bRunning;
	BOOL m_bPause;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // control bar embedded members
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// Generated message map functions
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnMenuStart();
	afx_msg void OnMenuStop();
	afx_msg void OnUpdateMenuStart(CCmdUI *pCmdUI);
	afx_msg void OnUpdateMenuStop(CCmdUI *pCmdUI);
	afx_msg void OnMenuPause();
	afx_msg void OnUpdateMenuPause(CCmdUI *pCmdUI);
	afx_msg void OnSubmenuSub1();
};


