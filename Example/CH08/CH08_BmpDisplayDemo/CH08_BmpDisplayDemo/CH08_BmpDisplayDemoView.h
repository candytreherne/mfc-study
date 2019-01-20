
// CH08_BmpDisplayDemoView.h : interface of the CCH08BmpDisplayDemoView class
//

#pragma once


class CCH08BmpDisplayDemoView : public CView
{
protected: // create from serialization only
	CCH08BmpDisplayDemoView() noexcept;
	DECLARE_DYNCREATE(CCH08BmpDisplayDemoView)

// Attributes
public:
	CCH08BmpDisplayDemoDoc* GetDocument() const;

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
	virtual ~CCH08BmpDisplayDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // debug version in CH08_BmpDisplayDemoView.cpp
inline CCH08BmpDisplayDemoDoc* CCH08BmpDisplayDemoView::GetDocument() const
   { return reinterpret_cast<CCH08BmpDisplayDemoDoc*>(m_pDocument); }
#endif

