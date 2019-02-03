
// EditDemoView.cpp : implementation of the CEditDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "EditDemo.h"
#endif

#include "EditDemoDoc.h"
#include "EditDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditDemoView

IMPLEMENT_DYNCREATE(CEditDemoView, CView)

BEGIN_MESSAGE_MAP(CEditDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CEditDemoView construction/destruction

CEditDemoView::CEditDemoView() noexcept
{
	// TODO: add construction code here

}

CEditDemoView::~CEditDemoView()
{
}

BOOL CEditDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CEditDemoView drawing

void CEditDemoView::OnDraw(CDC* /*pDC*/)
{
	CEditDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CEditDemoView printing

BOOL CEditDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEditDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEditDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CEditDemoView diagnostics

#ifdef _DEBUG
void CEditDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CEditDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEditDemoDoc* CEditDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEditDemoDoc)));
	return (CEditDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CEditDemoView message handlers


int CEditDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;


	m_wndEdit.Create(WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER | ES_AUTOHSCROLL,
		CRect(20, 20, 220, 36), this, 1234);

	return 0;
}
