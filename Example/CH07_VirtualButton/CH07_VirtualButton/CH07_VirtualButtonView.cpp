
// CH07_VirtualButtonView.cpp : implementation of the CCH07VirtualButtonView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CH07_VirtualButton.h"
#endif

#include "CH07_VirtualButtonDoc.h"
#include "CH07_VirtualButtonView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCH07VirtualButtonView

IMPLEMENT_DYNCREATE(CCH07VirtualButtonView, CView)

BEGIN_MESSAGE_MAP(CCH07VirtualButtonView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CCH07VirtualButtonView construction/destruction

CCH07VirtualButtonView::CCH07VirtualButtonView() noexcept
{
	// TODO: add construction code here
	m_BtnRect = CRect(10, 10, 210, 40);
	m_bClicked = FALSE;

}

CCH07VirtualButtonView::~CCH07VirtualButtonView()
{
}

BOOL CCH07VirtualButtonView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CCH07VirtualButtonView drawing

void CCH07VirtualButtonView::OnDraw(CDC* /*pDC*/)
{
	CCH07VirtualButtonDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CCH07VirtualButtonView printing

BOOL CCH07VirtualButtonView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCH07VirtualButtonView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCH07VirtualButtonView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CCH07VirtualButtonView diagnostics

#ifdef _DEBUG
void CCH07VirtualButtonView::AssertValid() const
{
	CView::AssertValid();
}

void CCH07VirtualButtonView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCH07VirtualButtonDoc* CCH07VirtualButtonView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCH07VirtualButtonDoc)));
	return (CCH07VirtualButtonDoc*)m_pDocument;
}
#endif //_DEBUG


// CCH07VirtualButtonView message handlers


void CCH07VirtualButtonView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (m_BtnRect.PtInRect(point))
	{
		m_bClicked = !m_bClicked;
		RedrawWindow(&m_BtnRect);
	}

	CView::OnLButtonDown(nFlags, point);

}


void CCH07VirtualButtonView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_bClicked)
	{
		m_bClicked = !m_bClicked;
		RedrawWindow(&m_BtnRect);
	}

	if (m_BtnRect.PtInRect(point))
	{
		AfxMessageBox(TEXT("버튼을 클릭했습니다."));
	}

	CView::OnLButtonUp(nFlags, point);
}


void CCH07VirtualButtonView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages
	CRect Rect(m_BtnRect);
	Rect += CRect(1, 1, 1, 1);
	dc.Rectangle(&Rect);
	dc.FillSolidRect(m_BtnRect, ::GetSysColor(COLOR_BTNFACE));

	if (m_bClicked)
	{
		dc.Draw3dRect(m_BtnRect,
			::GetSysColor(COLOR_3DSHADOW),
			::GetSysColor(COLOR_3DLIGHT));
	}
	else
	{
		dc.Draw3dRect(m_BtnRect,
			::GetSysColor(COLOR_3DLIGHT),
			::GetSysColor(COLOR_3DSHADOW));
	}

	dc.SetBkColor(::GetSysColor(COLOR_BTNFACE));
	dc.SetTextColor(::GetSysColor(COLOR_BTNTEXT));

	if (m_bClicked)
	{
		CRect Rect = m_BtnRect;
		Rect += CRect(0, 0, 2, 2);
		dc.DrawText(TEXT("Test button"), &Rect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}
	else
	{
		dc.DrawText(TEXT("Test button"), &m_BtnRect, DT_CENTER | DT_SINGLELINE | DT_VCENTER);
	}
}
