
// ch08_02View.cpp : implementation of the Cch0802View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ch08_02.h"
#endif

#include "ch08_02Doc.h"
#include "ch08_02View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cch0802View

IMPLEMENT_DYNCREATE(Cch0802View, CView)

BEGIN_MESSAGE_MAP(Cch0802View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Cch0802View construction/destruction

Cch0802View::Cch0802View() noexcept
{
	// TODO: add construction code here

}

Cch0802View::~Cch0802View()
{
}

BOOL Cch0802View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cch0802View drawing

void Cch0802View::OnDraw(CDC* /*pDC*/)
{
	Cch0802Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cch0802View printing

BOOL Cch0802View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cch0802View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cch0802View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cch0802View diagnostics

#ifdef _DEBUG
void Cch0802View::AssertValid() const
{
	CView::AssertValid();
}

void Cch0802View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cch0802Doc* Cch0802View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cch0802Doc)));
	return (Cch0802Doc*)m_pDocument;
}
#endif //_DEBUG


// Cch0802View message handlers


void Cch0802View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	CImage Image;
	Image.LoadFromResource(AfxGetResourceHandle(), IDB_BITMAP_LOGO);

	CDC *pDC = CDC::FromHandle(Image.GetDC());
	pDC->TextOutW(10, 10, TEXT("This is Vim LOGO."));
	Image.ReleaseDC();


	Image.BitBlt(dc.m_hDC, 0, 0);
}
