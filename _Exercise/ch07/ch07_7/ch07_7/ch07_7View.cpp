
// ch07_7View.cpp : implementation of the Cch077View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ch07_7.h"
#endif

#include "ch07_7Doc.h"
#include "ch07_7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cch077View

IMPLEMENT_DYNCREATE(Cch077View, CView)

BEGIN_MESSAGE_MAP(Cch077View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Cch077View construction/destruction

Cch077View::Cch077View() noexcept
{
	// TODO: add construction code here
	m_BtnRect = CRect(20, 20, 220, 50);
	m_bClicked = FALSE;

}

Cch077View::~Cch077View()
{
}

BOOL Cch077View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cch077View drawing

void Cch077View::OnDraw(CDC* /*pDC*/)
{
	Cch077Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cch077View printing

BOOL Cch077View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cch077View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cch077View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cch077View diagnostics

#ifdef _DEBUG
void Cch077View::AssertValid() const
{
	CView::AssertValid();
}

void Cch077View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cch077Doc* Cch077View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cch077Doc)));
	return (Cch077Doc*)m_pDocument;
}
#endif //_DEBUG


// Cch077View message handlers


void Cch077View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_BtnRect.PtInRect(point))
	{
		m_bClicked = !m_bClicked;
		RedrawWindow(&m_BtnRect);
	}

	CView::OnLButtonDown(nFlags, point);
}


void Cch077View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_bClicked)
	{
		m_bClicked = !m_bClicked;
		RedrawWindow(m_BtnRect);
	}

	if (m_BtnRect.PtInRect(point))
	{
		AfxMessageBox(TEXT("버튼을 클릭했습니다."));
	}

	CView::OnLButtonUp(nFlags, point);
}


void Cch077View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	CRect Rect(m_BtnRect);
	Rect += CRect(1, 1, 1, 1);
	CPoint OutCorner = CPoint(9, 9);
	CPoint InCorner = CPoint(3, 3);
	dc.RoundRect(Rect, OutCorner);
	
	CPen Pen;
	CPen* pOldPen;
	CBrush Brush(::GetSysColor(COLOR_BTNFACE));
	CBrush* pOldBrush = dc.SelectObject(&Brush);

	if (m_bClicked)
	{
		Pen.CreatePen(PS_SOLID | PS_INSIDEFRAME, 3, ::GetSysColor(COLOR_3DSHADOW));
		pOldPen = dc.SelectObject(&Pen);
		dc.RoundRect(m_BtnRect, InCorner);
	}
	else
	{
		Pen.CreatePen(PS_SOLID | PS_INSIDEFRAME, 3, ::GetSysColor(COLOR_3DLIGHT));
		pOldPen = dc.SelectObject(&Pen);
		dc.RoundRect(m_BtnRect, InCorner);
	}
	
	dc.SelectObject(pOldPen);
	dc.SelectObject(pOldBrush);

	dc.SetBkColor(::GetSysColor(COLOR_BTNFACE));
	dc.SetTextColor(::GetSysColor(COLOR_BTNTEXT));

	if (m_bClicked)
	{
		CRect Rect = m_BtnRect;
		Rect += CRect(0, 0, 2, 2);
		dc.DrawText(TEXT("OK"), &Rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}
	else
	{
		dc.DrawText(TEXT("OK"), &m_BtnRect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}


	


}
