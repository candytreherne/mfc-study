
// SemaphoreDemoView.cpp : implementation of the CSemaphoreDemoView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "SemaphoreDemo.h"
#endif

#include "SemaphoreDemoDoc.h"
#include "SemaphoreDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSemaphoreDemoView

IMPLEMENT_DYNCREATE(CSemaphoreDemoView, CView)

BEGIN_MESSAGE_MAP(CSemaphoreDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CSemaphoreDemoView construction/destruction

CSemaphoreDemoView::CSemaphoreDemoView() noexcept
{
	// TODO: add construction code here

}

CSemaphoreDemoView::~CSemaphoreDemoView()
{
}

BOOL CSemaphoreDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CSemaphoreDemoView drawing

void CSemaphoreDemoView::OnDraw(CDC* /*pDC*/)
{
	CSemaphoreDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CSemaphoreDemoView printing

BOOL CSemaphoreDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CSemaphoreDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSemaphoreDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CSemaphoreDemoView diagnostics

#ifdef _DEBUG
void CSemaphoreDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CSemaphoreDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSemaphoreDemoDoc* CSemaphoreDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSemaphoreDemoDoc)));
	return (CSemaphoreDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CSemaphoreDemoView message handlers


int CSemaphoreDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  Add your specialized creation code here
	SetTimer(100, 1000, NULL);

	return 0;
}


void CSemaphoreDemoView::OnTimer(UINT_PTR nIDEvent)
{
	CClientDC dc(this);
	dc.FillSolidRect(0, 0, 300, 300, RGB(200, 200, 200));

	for (int i = 0; i < 10; i++)
	{
		if (g_arString[i].GetAt(0) == '#')
			dc.SetTextColor(RGB(192, 0, 0));
		else
			dc.SetTextColor(RGB(192, 192, 192));

		dc.TextOut(30, 20 * i + 10, g_arString[i]);
	}

	CView::OnTimer(nIDEvent);
}
