
// StaticDemoView.cpp : implementation of the CStaticDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "StaticDemo.h"
#endif

#include "StaticDemoDoc.h"
#include "StaticDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStaticDemoView

IMPLEMENT_DYNCREATE(CStaticDemoView, CView)

BEGIN_MESSAGE_MAP(CStaticDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CStaticDemoView construction/destruction

CStaticDemoView::CStaticDemoView() noexcept
{
	// TODO: add construction code here

}

CStaticDemoView::~CStaticDemoView()
{
}

BOOL CStaticDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CStaticDemoView drawing

void CStaticDemoView::OnDraw(CDC* /*pDC*/)
{
	CStaticDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CStaticDemoView printing

BOOL CStaticDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CStaticDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CStaticDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CStaticDemoView diagnostics

#ifdef _DEBUG
void CStaticDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CStaticDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStaticDemoDoc* CStaticDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStaticDemoDoc)));
	return (CStaticDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CStaticDemoView message handlers


int CStaticDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// Example #1
	//m_wndStatic.Create(TEXT("CStatic"),
	//	WS_CHILD | WS_VISIBLE | SS_CENTER,
	//	CRect(20, 20, 120, 120), this, 1234);

	// Example #2
	m_wndStatic.Create(TEXT("CStatic"),
		WS_CHILD | WS_VISIBLE | SS_ICON | SS_CENTERIMAGE,
		CRect(20, 20, 120, 120), this, 1234);

	CWinApp *pApp = AfxGetApp();
	m_wndStatic.SetIcon(pApp->LoadIconW(IDR_MAINFRAME));


	return 0;
}
