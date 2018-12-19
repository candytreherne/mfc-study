
// CH7_02View.cpp : implementation of the CCH702View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CH7_02.h"
#endif

#include "CH7_02Doc.h"
#include "CH7_02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCH702View

IMPLEMENT_DYNCREATE(CCH702View, CView)

BEGIN_MESSAGE_MAP(CCH702View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCH702View construction/destruction

CCH702View::CCH702View() noexcept
{
	// TODO: add construction code here

}

CCH702View::~CCH702View()
{
}

BOOL CCH702View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCH702View drawing

void CCH702View::OnDraw(CDC* /*pDC*/)
{
	CCH702Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCH702View printing

BOOL CCH702View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCH702View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCH702View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCH702View diagnostics

#ifdef _DEBUG
void CCH702View::AssertValid() const
{
	CView::AssertValid();
}

void CCH702View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH702Doc* CCH702View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH702Doc)));
	return (CCH702Doc*)m_pDocument;
}
#endif //_DEBUG


// CCH702View message handlers


void CCH702View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages
	CPen pen;
	CPen* old_pen;
	pen.CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
	old_pen = dc.SelectObject(&pen);

	CBrush brush;
	CBrush* old_brush;
	brush.CreateSolidBrush(RGB(128, 128, 128));
	old_brush = dc.SelectObject(&brush);

	CRect rect;
	rect.SetRect(20, 20, 140, 140);
	dc.Rectangle(rect);

	dc.SelectObject(old_brush);
	dc.SelectObject(old_pen);
}
