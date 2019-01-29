
// CommandDemoView.cpp : implementation of the CCommandDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CommandDemo.h"
#endif

#include "CommandDemoDoc.h"
#include "CommandDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCommandDemoView

IMPLEMENT_DYNCREATE(CCommandDemoView, CView)

BEGIN_MESSAGE_MAP(CCommandDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CCommandDemoView construction/destruction

CCommandDemoView::CCommandDemoView() noexcept
{
	// TODO: add construction code here

}

CCommandDemoView::~CCommandDemoView()
{
}

BOOL CCommandDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCommandDemoView drawing

void CCommandDemoView::OnDraw(CDC* /*pDC*/)
{
	CCommandDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCommandDemoView printing

BOOL CCommandDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCommandDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCommandDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCommandDemoView diagnostics

#ifdef _DEBUG
void CCommandDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CCommandDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCommandDemoDoc* CCommandDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCommandDemoDoc)));
	return (CCommandDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CCommandDemoView message handlers


void CCommandDemoView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CMenu *pMainMenu = AfxGetMainWnd()->GetMenu();
	CMenu *pSubMenu = pMainMenu->GetSubMenu(4);

	CPoint ptMenu = point;
	ClientToScreen(&ptMenu);

	pSubMenu->TrackPopupMenu(TPM_RIGHTBUTTON | TPM_LEFTALIGN,
		ptMenu.x, ptMenu.y,
		this);

	CView::OnRButtonDown(nFlags, point);
}
