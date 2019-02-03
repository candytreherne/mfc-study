
// StaticDemoView.h : interface of the CStaticDemoView class
//

#pragma once


class CStaticDemoView : public CView
{
protected: // create from serialization only
	CStaticDemoView() noexcept;
	DECLARE_DYNCREATE(CStaticDemoView)

// Attributes
public:
	CStaticDemoDoc* GetDocument() const;

	CStatic m_wndStatic;

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
	virtual ~CStaticDemoView();
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
};

#ifndef _DEBUG  // debug version in StaticDemoView.cpp
inline CStaticDemoDoc* CStaticDemoView::GetDocument() const
   { return reinterpret_cast<CStaticDemoDoc*>(m_pDocument); }
#endif

