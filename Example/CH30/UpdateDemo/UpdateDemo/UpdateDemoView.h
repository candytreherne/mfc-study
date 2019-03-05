
// UpdateDemoView.h : interface of the CUpdateDemoView class
//

#pragma once


class CUpdateDemoView : public CView
{
protected: // create from serialization only
	CUpdateDemoView() noexcept;
	DECLARE_DYNCREATE(CUpdateDemoView)

// Attributes
public:
	CUpdateDemoDoc* GetDocument() const;

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
	virtual ~CUpdateDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UpdateDemoView.cpp
inline CUpdateDemoDoc* CUpdateDemoView::GetDocument() const
   { return reinterpret_cast<CUpdateDemoDoc*>(m_pDocument); }
#endif

