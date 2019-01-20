
// CH08_ImgOutDemoView.cpp : implementation of the CCH08ImgOutDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CH08_ImgOutDemo.h"
#endif

#include "CH08_ImgOutDemoDoc.h"
#include "CH08_ImgOutDemoView.h"

//#include <atlimage.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCH08ImgOutDemoView

IMPLEMENT_DYNCREATE(CCH08ImgOutDemoView, CView)

BEGIN_MESSAGE_MAP(CCH08ImgOutDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCH08ImgOutDemoView construction/destruction

CCH08ImgOutDemoView::CCH08ImgOutDemoView() noexcept
{
	// TODO: add construction code here

}

CCH08ImgOutDemoView::~CCH08ImgOutDemoView()
{
}

BOOL CCH08ImgOutDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCH08ImgOutDemoView drawing

void CCH08ImgOutDemoView::OnDraw(CDC* /*pDC*/)
{
	CCH08ImgOutDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCH08ImgOutDemoView printing

BOOL CCH08ImgOutDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCH08ImgOutDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCH08ImgOutDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCH08ImgOutDemoView diagnostics

#ifdef _DEBUG
void CCH08ImgOutDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CCH08ImgOutDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH08ImgOutDemoDoc* CCH08ImgOutDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH08ImgOutDemoDoc)));
	return (CCH08ImgOutDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CCH08ImgOutDemoView message handlers


void CCH08ImgOutDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages
	CString strImagePath = TEXT("tux.png");

	// #01
	//CImage Image;
	//HRESULT hResult = Image.Load(strImagePath);

	//if (FAILED(hResult))
	//{
	//	CString strtmp = TEXT("ERROR: Failed to load");
	//	strtmp += strImagePath + TEXT("\n");
	//	TRACE(strtmp);
	//	return;
	//}

	//Image.BitBlt(dc.m_hDC, 0, 0);

	// #02
	//CImage Image;

	//Image.LoadFromResource(AfxGetInstanceHandle(), IDB_BITMAP_TEST);
	//Image.BitBlt(dc.m_hDC, 0, 0);

	// #03
	CImage Image;

	Image.LoadFromResource(AfxGetInstanceHandle(), IDB_BITMAP_TEST);
	
	CDC* pDC = CDC::FromHandle(Image.GetDC());
	pDC->SetBkMode(TRANSPARENT);
	pDC->TextOutW(200, 30, TEXT("CImage sample!"));
	Image.ReleaseDC();

	Image.BitBlt(dc.m_hDC, 0, 0);


}

