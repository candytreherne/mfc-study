
// SaveGrayDemoView.cpp : implementation of the CSaveGrayDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SaveGrayDemo.h"
#endif

#include "SaveGrayDemoDoc.h"
#include "SaveGrayDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


inline void RGBtoGray(COLORREF& rgb)
{
	BYTE byGray = (GetRValue(rgb) * 30
		+ GetGValue(rgb) * 59
		+ GetBValue(rgb) * 11) / 100;

	rgb = RGB(byGray, byGray, byGray);
}


// CSaveGrayDemoView

IMPLEMENT_DYNCREATE(CSaveGrayDemoView, CView)

BEGIN_MESSAGE_MAP(CSaveGrayDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CSaveGrayDemoView construction/destruction

CSaveGrayDemoView::CSaveGrayDemoView() noexcept
{
	// TODO: add construction code here

}

CSaveGrayDemoView::~CSaveGrayDemoView()
{
}

BOOL CSaveGrayDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSaveGrayDemoView drawing

void CSaveGrayDemoView::OnDraw(CDC* /*pDC*/)
{
	CSaveGrayDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSaveGrayDemoView printing

BOOL CSaveGrayDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSaveGrayDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSaveGrayDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSaveGrayDemoView diagnostics

#ifdef _DEBUG
void CSaveGrayDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CSaveGrayDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSaveGrayDemoDoc* CSaveGrayDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSaveGrayDemoDoc)));
	return (CSaveGrayDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CSaveGrayDemoView message handlers


void CSaveGrayDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CWnd *pWndDesktop = GetDesktopWindow();
	CWindowDC ScrDC(pWndDesktop);
	CClientDC dc(this);

	CImage Image;
	Image.Create(300, 300, ScrDC.GetDeviceCaps(BITSPIXEL));

	CDC *pDC = CDC::FromHandle(Image.GetDC());
	pDC->BitBlt(0, 0, 300, 300, &ScrDC, 0, 0, SRCCOPY);
	Image.ReleaseDC();

	COLORREF rgb;

	for (int x = 0; x < 200; x++)
	{
		for (int y = 0; y < 200; y++)
		{
			rgb = Image.GetPixel(x, y);
			RGBtoGray(rgb);
			Image.SetPixel(x, y, rgb);
		}
	}

	Image.BitBlt(dc.m_hDC, 0, 0);

	CView::OnLButtonDown(nFlags, point);
}


void CSaveGrayDemoView::OnRButtonDown(UINT nFlags, CPoint point)
{
	CWnd *pWndDesktop = GetDesktopWindow();
	CWindowDC ScrDC(pWndDesktop);
	CClientDC dc(this);

	CRect Rect;
	pWndDesktop->GetWindowRect(&Rect);

	CImage Image;
	int cx = Rect.Width();
	int cy = Rect.Height();
	Image.Create(cx, cy, ScrDC.GetDeviceCaps(BITSPIXEL));

	CDC *pDC = CDC::FromHandle(Image.GetDC());
	pDC->BitBlt(0, 0, cx, cy, &ScrDC, 0, 0, SRCCOPY);
	dc.BitBlt(0, 0, cx, cy, &ScrDC, 0, 0, SRCCOPY);
	Image.ReleaseDC();

	Image.Save(TEXT("Desktop.jpg"), Gdiplus::ImageFormatJPEG);

	::ShellExecute(NULL, TEXT("open"), TEXT("Desktop.jpg"), NULL, NULL, SW_SHOW);

	CView::OnRButtonDown(nFlags, point);
}
