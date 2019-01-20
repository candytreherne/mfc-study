
// ch08_03View.cpp : implementation of the Cch0803View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ch08_03.h"
#endif

#include "ch08_03Doc.h"
#include "ch08_03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cch0803View

IMPLEMENT_DYNCREATE(Cch0803View, CView)

BEGIN_MESSAGE_MAP(Cch0803View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Cch0803View construction/destruction

Cch0803View::Cch0803View() noexcept
{
	// TODO: add construction code here

}

Cch0803View::~Cch0803View()
{
}

BOOL Cch0803View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Cch0803View drawing

void Cch0803View::OnDraw(CDC* /*pDC*/)
{
	Cch0803Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// Cch0803View printing

BOOL Cch0803View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Cch0803View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Cch0803View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Cch0803View diagnostics

#ifdef _DEBUG
void Cch0803View::AssertValid() const
{
	CView::AssertValid();
}

void Cch0803View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cch0803Doc* Cch0803View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cch0803Doc)));
	return (Cch0803Doc*)m_pDocument;
}
#endif //_DEBUG


// Cch0803View message handlers


void Cch0803View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	CImage front_image;
	CImage back_image;
	int width;
	int height;
	
	back_image.Load(TEXT("res/vim_logo.bmp"));
	front_image.Load(TEXT("res/tux-96.bmp"));

	width = back_image.GetWidth();
	height = back_image.GetHeight();
	
	back_image.AlphaBlend(dc.m_hDC, 100, 100, width, height, 0, 0, width, height, 127);
	
	width = front_image.GetWidth();
	height = front_image.GetHeight();
	
	front_image.AlphaBlend(dc.m_hDC, 0, 0, width, height, 0, 0, width, height, 127);
}
