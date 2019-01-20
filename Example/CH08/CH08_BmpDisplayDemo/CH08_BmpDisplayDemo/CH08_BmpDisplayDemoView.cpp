
// CH08_BmpDisplayDemoView.cpp : implementation of the CCH08BmpDisplayDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CH08_BmpDisplayDemo.h"
#endif

#include "CH08_BmpDisplayDemoDoc.h"
#include "CH08_BmpDisplayDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCH08BmpDisplayDemoView

IMPLEMENT_DYNCREATE(CCH08BmpDisplayDemoView, CView)

BEGIN_MESSAGE_MAP(CCH08BmpDisplayDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCH08BmpDisplayDemoView construction/destruction

CCH08BmpDisplayDemoView::CCH08BmpDisplayDemoView() noexcept
{
	// TODO: add construction code here

}

CCH08BmpDisplayDemoView::~CCH08BmpDisplayDemoView()
{
}

BOOL CCH08BmpDisplayDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCH08BmpDisplayDemoView drawing

void CCH08BmpDisplayDemoView::OnDraw(CDC* /*pDC*/)
{
	CCH08BmpDisplayDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCH08BmpDisplayDemoView printing

BOOL CCH08BmpDisplayDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCH08BmpDisplayDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCH08BmpDisplayDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCH08BmpDisplayDemoView diagnostics

#ifdef _DEBUG
void CCH08BmpDisplayDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CCH08BmpDisplayDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH08BmpDisplayDemoDoc* CCH08BmpDisplayDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH08BmpDisplayDemoDoc)));
	return (CCH08BmpDisplayDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CCH08BmpDisplayDemoView message handlers


void CCH08BmpDisplayDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages

	CDC MemDC;
	BITMAP bmpInfo;

	MemDC.CreateCompatibleDC(&dc);

	CBitmap bmp;
	CBitmap* pOldBmp = NULL;
	bmp.LoadBitmap(IDB_BITMAP_TEST_IMG_3);
	bmp.GetBitmap(&bmpInfo);
	pOldBmp = MemDC.SelectObject(&bmp);

	// BitBlt Example
	//dc.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &MemDC, 0, 0, SRCCOPY);

	// StretchBlt Example
	dc.StretchBlt(20, 20, bmpInfo.bmWidth * 2, bmpInfo.bmHeight * 2, &MemDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, SRCCOPY);

	//dc.TransparentBlt(20 * 2 + bmpInfo.bmWidth * 2, 20, bmpInfo.bmWidth * 2, bmpInfo.bmHeight * 2, &MemDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, RGB(255, 0, 255));
	BLENDFUNCTION bf;
	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.SourceConstantAlpha = 50;
	bf.AlphaFormat = 0;
	dc.AlphaBlend(20 * 2 + bmpInfo.bmWidth, 20, bmpInfo.bmWidth * 2, bmpInfo.bmHeight * 2, &MemDC, 0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, bf);

	MemDC.SelectObject(pOldBmp);
	
}
