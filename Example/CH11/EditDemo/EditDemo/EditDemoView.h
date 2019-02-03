
// EditDemoView.h : interface of the CEditDemoView class
//

#pragma once


class CEditDemoView : public CView
{
protected: // create from serialization only
	CEditDemoView() noexcept;
	DECLARE_DYNCREATE(CEditDemoView)

// Attributes
public:
	CEditDemoDoc* GetDocument() const;

	CEdit m_wndEdit;

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
	virtual ~CEditDemoView();
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

#ifndef _DEBUG  // debug version in EditDemoView.cpp
inline CEditDemoDoc* CEditDemoView::GetDocument() const
   { return reinterpret_cast<CEditDemoDoc*>(m_pDocument); }
#endif

