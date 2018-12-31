
// CH07_VirtualButtonView.h : interface of the CCH07VirtualButtonView class
//

#pragma once


class CCH07VirtualButtonView : public CView
{
protected: // create from serialization only
	CCH07VirtualButtonView() noexcept;
	DECLARE_DYNCREATE(CCH07VirtualButtonView)

// Attributes
public:
	CCH07VirtualButtonDoc* GetDocument() const;

	CRect m_BtnRect;
	BOOL m_bClicked;

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
	virtual ~CCH07VirtualButtonView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // debug version in CH07_VirtualButtonView.cpp
inline CCH07VirtualButtonDoc* CCH07VirtualButtonView::GetDocument() const
   { return reinterpret_cast<CCH07VirtualButtonDoc*>(m_pDocument); }
#endif

