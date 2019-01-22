
// FrameRgnView.h : interface of the CFrameRgnView class
//

#pragma once


class CFrameRgnView : public CView
{
protected: // create from serialization only
	CFrameRgnView() noexcept;
	DECLARE_DYNCREATE(CFrameRgnView)

// Attributes
public:
	CFrameRgnDoc* GetDocument() const;

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
	virtual ~CFrameRgnView();
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

#ifndef _DEBUG  // debug version in FrameRgnView.cpp
inline CFrameRgnDoc* CFrameRgnView::GetDocument() const
   { return reinterpret_cast<CFrameRgnDoc*>(m_pDocument); }
#endif

