
// ch07_5View.cpp : implementation of the Cch075View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ch07_5.h"
#endif

#include "ch07_5Doc.h"
#include "ch07_5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cch075View

IMPLEMENT_DYNCREATE(Cch075View, CView)

BEGIN_MESSAGE_MAP(Cch075View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Cch075View construction/destruction

Cch075View::Cch075View() noexcept
{
	// TODO: add construction code here

}

Cch075View::~Cch075View()
{
}

BOOL Cch075View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cch075View drawing

void Cch075View::OnDraw(CDC* /*pDC*/)
{
	Cch075Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cch075View printing

BOOL Cch075View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cch075View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cch075View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cch075View diagnostics

#ifdef _DEBUG
void Cch075View::AssertValid() const
{
	CView::AssertValid();
}

void Cch075View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cch075Doc* Cch075View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cch075Doc)));
	return (Cch075Doc*)m_pDocument;
}
#endif //_DEBUG


// Cch075View message handlers


void Cch075View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	CString strMessage = CString(TEXT("\t이것은 실습을 위한 \n 문자열입니다."));

	CFont Font;
	CFont* pOldFont;
	LOGFONT lf;

	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 20;
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
}
