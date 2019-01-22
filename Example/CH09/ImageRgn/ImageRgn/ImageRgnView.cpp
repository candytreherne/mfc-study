
// ImageRgnView.cpp : implementation of the CImageRgnView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "ImageRgn.h"
#endif

#include "ImageRgnDoc.h"
#include "ImageRgnView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageRgnView

IMPLEMENT_DYNCREATE(CImageRgnView, CView)

BEGIN_MESSAGE_MAP(CImageRgnView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CImageRgnView construction/destruction

CImageRgnView::CImageRgnView() noexcept
{
	// TODO: add construction code here

}

CImageRgnView::~CImageRgnView()
{
}

BOOL CImageRgnView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CImageRgnView drawing

void CImageRgnView::OnDraw(CDC* /*pDC*/)
{
	CImageRgnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CImageRgnView printing

BOOL CImageRgnView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImageRgnView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImageRgnView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CImageRgnView diagnostics

#ifdef _DEBUG
void CImageRgnView::AssertValid() const
{
	CView::AssertValid();
}

void CImageRgnView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageRgnDoc* CImageRgnView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageRgnDoc)));
	return (CImageRgnDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageRgnView message handlers


int CImageRgnView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	rect_visible = CRect(0, 0, 0, 0);
	image_sample.LoadFromResource(AfxGetInstanceHandle(), IDB_BITMAP_LOGO);

	return 0;
}


void CImageRgnView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	image_sample.AlphaBlend(dc.m_hDC, 0, 0, 50);

	CRgn rgn;
	rgn.CreateEllipticRgn(rect_visible.left,
		rect_visible.top,
		rect_visible.right,
		rect_visible.bottom);
	dc.SelectClipRgn(&rgn);

	image_sample.BitBlt(dc.m_hDC, 0, 0);
}


void CImageRgnView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (nFlags & MK_LBUTTON)
	{
		rect_visible = CRect(point.x - 100,
			point.y - 100,
			point.x + 100,
			point.y + 100);
		
		RedrawWindow();
	}

	CView::OnMouseMove(nFlags, point);
}


void CImageRgnView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	rect_visible = CRect(0, 0, 0, 0);
	RedrawWindow();

	CView::OnLButtonUp(nFlags, point);
}
