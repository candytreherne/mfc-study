
// TextRgnView.cpp : implementation of the CTextRgnView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "TextRgn.h"
#endif

#include "TextRgnDoc.h"
#include "TextRgnView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextRgnView

IMPLEMENT_DYNCREATE(CTextRgnView, CView)

BEGIN_MESSAGE_MAP(CTextRgnView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CTextRgnView construction/destruction

CTextRgnView::CTextRgnView() noexcept
{
	// TODO: add construction code here

}

CTextRgnView::~CTextRgnView()
{
}

BOOL CTextRgnView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTextRgnView drawing

void CTextRgnView::OnDraw(CDC* /*pDC*/)
{
	CTextRgnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CTextRgnView printing

BOOL CTextRgnView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTextRgnView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTextRgnView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CTextRgnView diagnostics

#ifdef _DEBUG
void CTextRgnView::AssertValid() const
{
	CView::AssertValid();
}

void CTextRgnView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextRgnDoc* CTextRgnView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextRgnDoc)));
	return (CTextRgnDoc*)m_pDocument;
}
#endif //_DEBUG


// CTextRgnView message handlers


void CTextRgnView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	CRect rect_left = CRect(50, 50, 250, 150);
	CRect rect_right = CRect(250, 50, 450, 150);
	dc.FillSolidRect(&rect_left, RGB(255, 128, 0));
	dc.FillSolidRect(&rect_right, RGB(25, 0, 192));

	CRgn rgn_left;
	CRgn rgn_right;
	rgn_left.CreateRectRgnIndirect(rect_left);
	rgn_right.CreateRectRgnIndirect(rect_right);

	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 72;
	wsprintf(lf.lfFaceName, TEXT("%s"), TEXT("Impact"));
	CFont new_font;
	new_font.CreateFontIndirectW(&lf);
	CFont *old_font = dc.SelectObject(&new_font);

	dc.SetBkMode(TRANSPARENT);

	dc.SetTextColor(RGB(25, 0, 192));
	dc.SelectClipRgn(&rgn_left);
	dc.TextOutW(110, 65, TEXT("TEST STRING"));

	dc.SetTextColor(RGB(255, 128, 0));
	dc.SelectClipRgn(&rgn_right);
	dc.TextOutW(110, 65, TEXT("TEST STRING"));

	dc.SelectObject(old_font);


}
