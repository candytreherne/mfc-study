
// ch07_08View.cpp : implementation of the Cch0708View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ch07_08.h"
#endif

#include "ch07_08Doc.h"
#include "ch07_08View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cch0708View

IMPLEMENT_DYNCREATE(Cch0708View, CView)

BEGIN_MESSAGE_MAP(Cch0708View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// Cch0708View construction/destruction

Cch0708View::Cch0708View() noexcept
	:isLButtonDown(false)
	,start_pt(CPoint(0, 0))
	,end_pt(CPoint(0,0))
{
	// TODO: add construction code here

}

Cch0708View::~Cch0708View()
{
}

BOOL Cch0708View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cch0708View drawing

void Cch0708View::OnDraw(CDC* /*pDC*/)
{
	Cch0708Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cch0708View printing

BOOL Cch0708View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cch0708View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cch0708View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cch0708View diagnostics

#ifdef _DEBUG
void Cch0708View::AssertValid() const
{
	CView::AssertValid();
}

void Cch0708View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cch0708Doc* Cch0708View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cch0708Doc)));
	return (Cch0708Doc*)m_pDocument;
}
#endif //_DEBUG


// Cch0708View message handlers


void Cch0708View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	if (isLButtonDown)
	{
		// Set Pen
		CPen rect_pen;
		rect_pen.CreatePen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT, 2, RGB(50, 100, 127));
		CPen* old_pen = dc.SelectObject(&rect_pen);

		// Set Brush
		COLORREF rect_color = RGB(150, 200, 255);
		CBrush rect_brush(rect_color);
		CBrush* old_brush = dc.SelectObject(&rect_brush);

		// Set & Draw Rect
		CRect rect;
		rect = CRect(start_pt, end_pt);
		dc.Rectangle(rect);
	
		// Set Font
		CFont font;
		CFont* old_font;
		LOGFONT lf;
		int font_height = rect.Height() / 5;
		if (font_height > 50)
		{
			font_height = 50;
		}
		::ZeroMemory(&lf, sizeof(lf));
		lf.lfHeight = font_height;
		wsprintf(lf.lfFaceName, TEXT("%s"), TEXT("D2Coding ligature"));
		font.CreateFontIndirectW(&lf);
		old_font = dc.SelectObject(&font);
		dc.SetBkColor(rect_color);
		
		// Draw Text
		dc.DrawText(TEXT("Hello"), rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);

		// Release Font, Brush, Pen
		dc.SelectObject(old_font);
		dc.SelectObject(old_brush);
		dc.SelectObject(old_pen);
	}

}


void Cch0708View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	isLButtonDown = true;
	start_pt = point;

	CView::OnLButtonDown(nFlags, point);
}


void Cch0708View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	isLButtonDown = false;

	start_pt = CPoint(0, 0);
	end_pt = CPoint(0, 0);
	RedrawWindow();
	ReleaseCapture();

	CView::OnLButtonUp(nFlags, point);
}


void Cch0708View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isLButtonDown)
	{
		SetCapture();
		end_pt = point;

		CRect window;
		GetWindowRect(window);

		if (end_pt.x > window.Width())
			end_pt.x = window.Width();
		else if (end_pt.x < 0)
			end_pt.x = 0;

		if (end_pt.y > window.Height())
			end_pt.y = window.Height();
		else if (end_pt.y < 0)
			end_pt.y = 0;

		RedrawWindow();
	}

	CView::OnMouseMove(nFlags, point);
}
