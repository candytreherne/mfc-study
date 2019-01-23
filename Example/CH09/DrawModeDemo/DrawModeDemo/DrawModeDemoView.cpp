
// DrawModeDemoView.cpp : implementation of the CDrawModeDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DrawModeDemo.h"
#endif

#include "DrawModeDemoDoc.h"
#include "DrawModeDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDrawModeDemoView

IMPLEMENT_DYNCREATE(CDrawModeDemoView, CView)

BEGIN_MESSAGE_MAP(CDrawModeDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_PAINT()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CDrawModeDemoView construction/destruction

CDrawModeDemoView::CDrawModeDemoView() noexcept
{
	// TODO: add construction code here
	m_ptBegin = CPoint(0, 0);
	m_ptEnd= CPoint(0, 0);

	m_ptDragBegin = CPoint(0, 0);
	m_ptDragEnd= CPoint(0, 0);
}

CDrawModeDemoView::~CDrawModeDemoView()
{
}

BOOL CDrawModeDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDrawModeDemoView drawing

void CDrawModeDemoView::OnDraw(CDC* /*pDC*/)
{
	CDrawModeDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CDrawModeDemoView printing

BOOL CDrawModeDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDrawModeDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDrawModeDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CDrawModeDemoView diagnostics

#ifdef _DEBUG
void CDrawModeDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CDrawModeDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDrawModeDemoDoc* CDrawModeDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDrawModeDemoDoc)));
	return (CDrawModeDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CDrawModeDemoView message handlers


void CDrawModeDemoView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (GetCapture() == this)
	{
		m_ptBegin = m_ptDragBegin;
		m_ptEnd = m_ptDragEnd;
		//m_ptEnd = point;
		RedrawWindow();
	}

	ReleaseCapture();

	CView::OnLButtonUp(nFlags, point);
}


void CDrawModeDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	SetCapture();

	m_ptDragBegin = point;
	m_ptDragEnd = point;

	CView::OnLButtonDown(nFlags, point);
}


void CDrawModeDemoView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (GetCapture() == this)
	{
		DrawInvertLine(point);
	}

	CView::OnMouseMove(nFlags, point);
}


void CDrawModeDemoView::DrawInvertLine(CPoint point)
{
	// TODO: Add your implementation code here.
	CClientDC dc(this);

	CPen NewPen(PS_SOLID, 40, RGB(0, 128, 0));
	CPen *pOldPen = (CPen *)dc.SelectObject(&NewPen);

	dc.SetROP2(R2_NOT);

	dc.MoveTo(m_ptDragBegin);
	dc.LineTo(m_ptDragEnd);

	m_ptDragEnd = point;

	dc.MoveTo(m_ptDragBegin);
	dc.LineTo(m_ptDragEnd);

	dc.SelectObject(pOldPen);
}


void CDrawModeDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	CImage Image;
	Image.Load(TEXT("res/vim_logo.bmp"));
	Image.BitBlt(dc.m_hDC, 0, 0);

	CPen NewPen(PS_SOLID, 40, RGB(192, 0, 0));
	CPen *pOldPen = dc.SelectObject(&NewPen);

	dc.MoveTo(m_ptBegin);
	dc.LineTo(m_ptEnd);

	dc.SelectObject(pOldPen);
}


void CDrawModeDemoView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CWnd *pWnd = GetDesktopWindow();
	CWindowDC dc(pWnd);
	CPen NewPen(PS_SOLID, 10, RGB(0, 0, 0));
	CPen *pOldPen = dc.SelectObject(&NewPen);

	int nPrevMode = dc.SetROP2(R2_NOTXORPEN);

	for (int i = 0; i < 300; i += 3)
	{
		dc.Rectangle(20, 20, 210 + i, 210 + i);
		::Sleep(100);
		dc.Rectangle(20, 20, 210 + i, 210 + i);
	}

	dc.SelectObject(pOldPen);
	dc.SetROP2(nPrevMode);
	pWnd->RedrawWindow();

	CView::OnRButtonDown(nFlags, point);
}
