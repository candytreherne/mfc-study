
// ImageRgnView.h : interface of the CImageRgnView class
//

#pragma once


class CImageRgnView : public CView
{
protected: // create from serialization only
	CImageRgnView() noexcept;
	DECLARE_DYNCREATE(CImageRgnView)

// Attributes
public:
	CImageRgnDoc* GetDocument() const;

	CImage image_sample;
	CRect rect_visible;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CImageRgnView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in ImageRgnView.cpp
inline CImageRgnDoc* CImageRgnView::GetDocument() const
   { return reinterpret_cast<CImageRgnDoc*>(m_pDocument); }
#endif

