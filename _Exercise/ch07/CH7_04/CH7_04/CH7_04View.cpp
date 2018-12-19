
// CH7_04View.cpp : implementation of the CCH704View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CH7_04.h"
#endif

#include "CH7_04Doc.h"
#include "CH7_04View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCH704View

IMPLEMENT_DYNCREATE(CCH704View, CView)

BEGIN_MESSAGE_MAP(CCH704View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCH704View construction/destruction

CCH704View::CCH704View() noexcept
{
	// TODO: add construction code here

}

CCH704View::~CCH704View()
{
}

BOOL CCH704View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCH704View drawing

void CCH704View::OnDraw(CDC* /*pDC*/)
{
	CCH704Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCH704View printing

BOOL CCH704View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCH704View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCH704View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCH704View diagnostics

#ifdef _DEBUG
void CCH704View::AssertValid() const
{
	CView::AssertValid();
}

void CCH704View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH704Doc* CCH704View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH704Doc)));
	return (CCH704Doc*)m_pDocument;
}
#endif //_DEBUG


// CCH704View message handlers


void CCH704View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages
	CPen pen;
	pen.CreatePen(PS_NULL, 1, RGB(0, 0, 0));
	CPen* old_pen = dc.SelectObject(&pen);

	CRect win_rect;
	GetClientRect(win_rect);

	CBrush back_brush = RGB(0, 120, 120);
	CBrush* old_brush = dc.SelectObject(&back_brush);
	dc.Rectangle(win_rect);
	dc.SelectObject(&old_brush);
	
	int offset = 20;
	CRect inner_win_rect;
	inner_win_rect.left = win_rect.left + offset * 2;
	inner_win_rect.right = win_rect.right - offset * 2;
	inner_win_rect.top = win_rect.top + offset * 2;
	inner_win_rect.bottom = win_rect.bottom - offset * 2;

	CBrush inner_brush = RGB(255, 255, 255);
	old_brush = dc.SelectObject(&inner_brush);

	dc.Rectangle(inner_win_rect);
	// top
	dc.Rectangle(win_rect.left + offset * 2, win_rect.top + offset, win_rect.right - offset * 2, win_rect.bottom - offset * 2);
	// left
	dc.Rectangle(win_rect.left + offset, win_rect.top + offset * 2, win_rect.left + offset * 3, win_rect.bottom - offset * 2);
	// bottom
	dc.Rectangle(win_rect.left + offset * 2, win_rect.bottom - offset * 3, win_rect.right - offset * 2, win_rect.bottom - offset);
	// right
	dc.Rectangle(win_rect.right - offset * 3, win_rect.top + offset * 2, win_rect.right - offset, win_rect.bottom - offset * 2);
	// top-left corner
	dc.Ellipse(inner_win_rect.left - offset, inner_win_rect.top - offset, inner_win_rect.left + offset, inner_win_rect.top + offset);
	// bottom-left corner
	dc.Ellipse(inner_win_rect.left - offset, inner_win_rect.bottom - offset, inner_win_rect.left + offset, inner_win_rect.bottom + offset);
	// bottom-right corner
	dc.Ellipse(inner_win_rect.right - offset, inner_win_rect.bottom - offset, inner_win_rect.right + offset, inner_win_rect.bottom + offset);
	// top-right corner
	dc.Ellipse(inner_win_rect.right - offset, inner_win_rect.top - offset, inner_win_rect.right + offset, inner_win_rect.top + offset);
	
	dc.SelectObject(old_brush);

	dc.SelectObject(old_pen);
}
