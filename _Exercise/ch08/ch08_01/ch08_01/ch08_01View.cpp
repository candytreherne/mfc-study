
// ch08_01View.cpp : implementation of the Cch0801View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ch08_01.h"
#endif

#include "ch08_01Doc.h"
#include "ch08_01View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cch0801View

IMPLEMENT_DYNCREATE(Cch0801View, CView)

BEGIN_MESSAGE_MAP(Cch0801View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Cch0801View construction/destruction

Cch0801View::Cch0801View() noexcept
{
	// TODO: add construction code here

}

Cch0801View::~Cch0801View()
{
}

BOOL Cch0801View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cch0801View drawing

void Cch0801View::OnDraw(CDC* /*pDC*/)
{
	Cch0801Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cch0801View printing

BOOL Cch0801View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cch0801View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cch0801View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cch0801View diagnostics

#ifdef _DEBUG
void Cch0801View::AssertValid() const
{
	CView::AssertValid();
}

void Cch0801View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cch0801Doc* Cch0801View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cch0801Doc)));
	return (Cch0801Doc*)m_pDocument;
}
#endif //_DEBUG


// Cch0801View message handlers


void Cch0801View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	CImage Image;
	Image.LoadFromResource(AfxGetInstanceHandle(), IDB_BITMAP_LOGO);
	Image.BitBlt(dc.m_hDC, 0, 0);
}
