
// CommandDemoView.h : interface of the CCommandDemoView class
//

#pragma once


class CCommandDemoView : public CView
{
protected: // create from serialization only
	CCommandDemoView() noexcept;
	DECLARE_DYNCREATE(CCommandDemoView)

// Attributes
public:
	CCommandDemoDoc* GetDocument() const;

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
	virtual ~CCommandDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CommandDemoView.cpp
inline CCommandDemoDoc* CCommandDemoView::GetDocument() const
   { return reinterpret_cast<CCommandDemoDoc*>(m_pDocument); }
#endif

