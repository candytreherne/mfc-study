
// TextRgnView.h : interface of the CTextRgnView class
//

#pragma once


class CTextRgnView : public CView
{
protected: // create from serialization only
	CTextRgnView() noexcept;
	DECLARE_DYNCREATE(CTextRgnView)

// Attributes
public:
	CTextRgnDoc* GetDocument() const;

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
	virtual ~CTextRgnView();
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

#ifndef _DEBUG  // debug version in TextRgnView.cpp
inline CTextRgnDoc* CTextRgnView::GetDocument() const
   { return reinterpret_cast<CTextRgnDoc*>(m_pDocument); }
#endif

