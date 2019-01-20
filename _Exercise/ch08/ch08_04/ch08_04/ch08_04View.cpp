
// ch08_04View.cpp : implementation of the Cch0804View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ch08_04.h"
#endif

#include "ch08_04Doc.h"
#include "ch08_04View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cch0804View

IMPLEMENT_DYNCREATE(Cch0804View, CView)

BEGIN_MESSAGE_MAP(Cch0804View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Cch0804View construction/destruction

Cch0804View::Cch0804View() noexcept
{
	// TODO: add construction code here

}

Cch0804View::~Cch0804View()
{
}

BOOL Cch0804View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cch0804View drawing

void Cch0804View::OnDraw(CDC* /*pDC*/)
{
	Cch0804Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cch0804View printing

BOOL Cch0804View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cch0804View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cch0804View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cch0804View diagnostics

#ifdef _DEBUG
void Cch0804View::AssertValid() const
{
	CView::AssertValid();
}

void Cch0804View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cch0804Doc* Cch0804View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cch0804Doc)));
	return (Cch0804Doc*)m_pDocument;
}
#endif //_DEBUG


// Cch0804View message handlers


void Cch0804View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	CImage back_image;
	CImage front_image;

	back_image.Load(TEXT("res/vim_logo.bmp"));
	front_image.Load(TEXT("res/tux-96.bmp"));

	back_image.BitBlt(dc.m_hDC, 0, 0);

	CDC *pDC = CDC::FromHandle(front_image.GetDC());
	
	CFont font;
	CFont *old_font;
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	wsprintf(lf.lfFaceName, TEXT("%s"), TEXT("Impact"));
	lf.lfHeight = 100;
	font.CreateFontIndirectW(&lf);
	old_font = pDC->SelectObject(&font);
	
	pDC->SetTextColor(RGB(255, 0, 255));
	pDC->SetBkMode(TRANSPARENT);
	pDC->TextOutW(50, 200, TEXT("I'm tux."));
	pDC->SelectObject(old_font);
	font.DeleteObject();

	int width;
	int height;

	width = front_image.GetWidth();
	height = front_image.GetHeight();

	dc.TransparentBlt(500, 250, width, height, pDC, 0, 0, width, height, RGB(255, 0, 255));
	front_image.ReleaseDC();

}
