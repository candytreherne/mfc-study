
// FrameRgnView.cpp : implementation of the CFrameRgnView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "FrameRgn.h"
#endif

#include "FrameRgnDoc.h"
#include "FrameRgnView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFrameRgnView

IMPLEMENT_DYNCREATE(CFrameRgnView, CView)

BEGIN_MESSAGE_MAP(CFrameRgnView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CFrameRgnView construction/destruction

CFrameRgnView::CFrameRgnView() noexcept
{
	// TODO: add construction code here

}

CFrameRgnView::~CFrameRgnView()
{
}

BOOL CFrameRgnView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CFrameRgnView drawing

void CFrameRgnView::OnDraw(CDC* /*pDC*/)
{
	CFrameRgnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CFrameRgnView printing

BOOL CFrameRgnView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFrameRgnView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFrameRgnView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CFrameRgnView diagnostics

#ifdef _DEBUG
void CFrameRgnView::AssertValid() const
{
	CView::AssertValid();
}

void CFrameRgnView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFrameRgnDoc* CFrameRgnView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFrameRgnDoc)));
	return (CFrameRgnDoc*)m_pDocument;
}
#endif //_DEBUG


// CFrameRgnView message handlers


int CFrameRgnView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here

	return 0;
}
