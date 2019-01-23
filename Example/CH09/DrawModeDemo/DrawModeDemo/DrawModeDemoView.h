
// DrawModeDemoView.h : interface of the CDrawModeDemoView class
//

#pragma once


class CDrawModeDemoView : public CView
{
protected: // create from serialization only
	CDrawModeDemoView() noexcept;
	DECLARE_DYNCREATE(CDrawModeDemoView)

// Attributes
public:
	CDrawModeDemoDoc* GetDocument() const;

	CPoint m_ptBegin;
	CPoint m_ptEnd;
	CPoint m_ptDragBegin;
	CPoint m_ptDragEnd;

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
	virtual ~CDrawModeDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void DrawInvertLine(CPoint point);
	afx_msg void OnPaint();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in DrawModeDemoView.cpp
inline CDrawModeDemoDoc* CDrawModeDemoView::GetDocument() const
   { return reinterpret_cast<CDrawModeDemoDoc*>(m_pDocument); }
#endif

