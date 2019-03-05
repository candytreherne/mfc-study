
// UpdateDemoView.cpp : implementation of the CUpdateDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "UpdateDemo.h"
#endif

#include "UpdateDemoDoc.h"
#include "UpdateDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CUpdateDemoView

IMPLEMENT_DYNCREATE(CUpdateDemoView, CView)

BEGIN_MESSAGE_MAP(CUpdateDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CUpdateDemoView construction/destruction

CUpdateDemoView::CUpdateDemoView() noexcept
{
	// TODO: add construction code here

}

CUpdateDemoView::~CUpdateDemoView()
{
}

BOOL CUpdateDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CUpdateDemoView drawing

void CUpdateDemoView::OnDraw(CDC* /*pDC*/)
{
	CUpdateDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CUpdateDemoView printing

BOOL CUpdateDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CUpdateDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CUpdateDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CUpdateDemoView diagnostics

#ifdef _DEBUG
void CUpdateDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CUpdateDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CUpdateDemoDoc* CUpdateDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CUpdateDemoDoc)));
	return (CUpdateDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CUpdateDemoView message handlers
