
// ch07_6View.cpp : implementation of the Cch076View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ch07_6.h"
#endif

#include "ch07_6Doc.h"
#include "ch07_6View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cch076View

IMPLEMENT_DYNCREATE(Cch076View, CView)

BEGIN_MESSAGE_MAP(Cch076View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Cch076View construction/destruction

Cch076View::Cch076View() noexcept
{
	// TODO: add construction code here

}

Cch076View::~Cch076View()
{
}

BOOL Cch076View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cch076View drawing

void Cch076View::OnDraw(CDC* /*pDC*/)
{
	Cch076Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cch076View printing

BOOL Cch076View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cch076View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cch076View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cch076View diagnostics

#ifdef _DEBUG
void Cch076View::AssertValid() const
{
	CView::AssertValid();
}

void Cch076View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cch076Doc* Cch076View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cch076Doc)));
	return (Cch076Doc*)m_pDocument;
}
#endif //_DEBUG


// Cch076View message handlers


void Cch076View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
	CString strMessage = CString(TEXT("\t이것은 실습을 위한 \n 문자열입니다."));

	CFont Font;
	CFont* pOldFont;
	LOGFONT lf;

	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 20;
	lf.lfItalic = TRUE;
	lf.lfWeight = 700;
	lf.lfUnderline = TRUE;
	wsprintf(lf.lfFaceName, TEXT("%s"), TEXT("Arial"));
	Font.CreateFontIndirectW(&lf);
	pOldFont = dc.SelectObject(&Font);
	
	// TextOut
	dc.TextOutW(10, 10, strMessage);

	// TabbedTextOut
	int nTabStop = 40;
	dc.TabbedTextOutW(10, 30, strMessage, 1, &nTabStop, 10);

	// DrawText
	dc.DrawText(strMessage, CRect(10, 50, 500, 100), DT_LEFT);

	dc.SelectObject(pOldFont);
				   // Do not call CView::OnPaint() for painting messages
}
