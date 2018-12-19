
// CH7_03View.cpp : implementation of the CCH703View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CH7_03.h"
#endif

#include "CH7_03Doc.h"
#include "CH7_03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCH703View

IMPLEMENT_DYNCREATE(CCH703View, CView)

BEGIN_MESSAGE_MAP(CCH703View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCH703View construction/destruction

CCH703View::CCH703View() noexcept
{
	// TODO: add construction code here

}

CCH703View::~CCH703View()
{
}

BOOL CCH703View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCH703View drawing

void CCH703View::OnDraw(CDC* /*pDC*/)
{
	CCH703Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCH703View printing

BOOL CCH703View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCH703View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCH703View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCH703View diagnostics

#ifdef _DEBUG
void CCH703View::AssertValid() const
{
	CView::AssertValid();
}

void CCH703View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH703Doc* CCH703View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH703Doc)));
	return (CCH703Doc*)m_pDocument;
}
#endif //_DEBUG


// CCH703View message handlers


void CCH703View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(192, 192, 192);

	CPen pen;
	pen.CreatePen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT | PS_JOIN_MITER, 5, &lb);
	CPen* old_pen = dc.SelectObject(&pen);

	CBrush brush(RGB(200, 200, 200));
	CBrush* old_brush = dc.SelectObject(&brush);

	int width = 400;
	int height = 460;
	CPoint pos = CPoint(50, 50);

	dc.BeginPath();
	dc.MoveTo(pos.x + width / 2, pos.y);
	dc.LineTo(pos.x + width, pos.y + height / 4);
	dc.LineTo(pos.x + width, pos.y + height * 3 / 4);
	dc.LineTo(pos.x + width / 2, pos.y + height);
	dc.LineTo(pos.x, pos.y + height * 3 / 4);
	dc.LineTo(pos.x, pos.y + height / 4);
	dc.EndPath();
	dc.StrokeAndFillPath();

	dc.SelectObject(old_brush);
	dc.SelectObject(old_pen);
}
