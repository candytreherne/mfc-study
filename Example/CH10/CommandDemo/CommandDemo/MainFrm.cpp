
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "CommandDemo.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_MENU_START, &CMainFrame::OnMenuStart)
	ON_COMMAND(ID_MENU_STOP, &CMainFrame::OnMenuStop)
	ON_UPDATE_COMMAND_UI(ID_MENU_START, &CMainFrame::OnUpdateMenuStart)
	ON_UPDATE_COMMAND_UI(ID_MENU_STOP, &CMainFrame::OnUpdateMenuStop)
	ON_COMMAND(ID_MENU_PAUSE, &CMainFrame::OnMenuPause)
	ON_UPDATE_COMMAND_UI(ID_MENU_PAUSE, &CMainFrame::OnUpdateMenuPause)
	ON_COMMAND(ID_SUBMENU_SUB1, &CMainFrame::OnSubmenuSub1)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
	m_bRunning = FALSE;
	m_bPause = FALSE;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers



void CMainFrame::OnMenuStart()
{
	m_bRunning = TRUE;
	AfxMessageBox(TEXT("시작 메뉴를 선택하였습니다."));
}


void CMainFrame::OnMenuStop()
{
	m_bRunning = FALSE;
	AfxMessageBox(TEXT("종료 메뉴를 선택하였습니다."));
}


void CMainFrame::OnUpdateMenuStart(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(!m_bRunning);
}


void CMainFrame::OnUpdateMenuStop(CCmdUI *pCmdUI)
{
	pCmdUI->Enable(m_bRunning);
}


void CMainFrame::OnMenuPause()
{
	if (m_bPause)
		AfxMessageBox(TEXT("다시 시작합니다."));
	else
		AfxMessageBox(TEXT("일시 정지 합니다."));

	m_bPause = !m_bPause;
}


void CMainFrame::OnUpdateMenuPause(CCmdUI *pCmdUI)
{
	//if (m_bPause)
	//	pCmdUI->SetText(TEXT("Restart"));
	//else
	//	pCmdUI->SetText(TEXT("Pause"));

	if (m_bPause)
		pCmdUI->SetCheck(TRUE);
	else
		pCmdUI->SetCheck(FALSE);

}


void CMainFrame::OnSubmenuSub1()
{
	AfxMessageBox(TEXT("서브 메뉴를 선택하였습니다."));
}
