
// SaveGrayDemoView.h : interface of the CSaveGrayDemoView class
//

#pragma once


class CSaveGrayDemoView : public CView
{
protected: // create from serialization only
	CSaveGrayDemoView() noexcept;
	DECLARE_DYNCREATE(CSaveGrayDemoView)

// Attributes
public:
	CSaveGrayDemoDoc* GetDocument() const;

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
	virtual ~CSaveGrayDemoView();
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
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in SaveGrayDemoView.cpp
inline CSaveGrayDemoDoc* CSaveGrayDemoView::GetDocument() const
   { return reinterpret_cast<CSaveGrayDemoDoc*>(m_pDocument); }
#endif

