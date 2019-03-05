
// SemaphoreDemoView.h : interface of the CSemaphoreDemoView class
//

#pragma once


class CSemaphoreDemoView : public CView
{
protected: // create from serialization only
	CSemaphoreDemoView() noexcept;
	DECLARE_DYNCREATE(CSemaphoreDemoView)

// Attributes
public:
	CSemaphoreDemoDoc* GetDocument() const;

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
	virtual ~CSemaphoreDemoView();
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
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // debug version in SemaphoreDemoView.cpp
inline CSemaphoreDemoDoc* CSemaphoreDemoView::GetDocument() const
   { return reinterpret_cast<CSemaphoreDemoDoc*>(m_pDocument); }
#endif

