
// CH7_01View.cpp : implementation of the CCH701View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CH7_01.h"
#endif

#include "CH7_01Doc.h"
#include "CH7_01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCH701View

IMPLEMENT_DYNCREATE(CCH701View, CView)

BEGIN_MESSAGE_MAP(CCH701View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCH701View construction/destruction

CCH701View::CCH701View() noexcept
{
	// TODO: add construction code here

}

CCH701View::~CCH701View()
{
}

BOOL CCH701View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCH701View drawing

void CCH701View::OnDraw(CDC* /*pDC*/)
{
	CCH701Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here

}


// CCH701View printing

BOOL CCH701View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCH701View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCH701View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCH701View diagnostics

#ifdef _DEBUG
void CCH701View::AssertValid() const
{
	CView::AssertValid();
}

void CCH701View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH701Doc* CCH701View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH701Doc)));
	return (CCH701Doc*)m_pDocument;
}
#endif //_DEBUG


// CCH701View message handlers


void CCH701View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	dc.Rectangle(20, 20, 140, 140);
}
