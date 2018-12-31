
// ch07_7View.h : interface of the Cch077View class
//

#pragma once


class Cch077View : public CView
{
protected: // create from serialization only
	Cch077View() noexcept;
	DECLARE_DYNCREATE(Cch077View)

// Attributes
public:
	Cch077Doc* GetDocument() const;

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
	virtual ~Cch077View();
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

#ifndef _DEBUG  // debug version in ch07_7View.cpp
inline Cch077Doc* Cch077View::GetDocument() const
   { return reinterpret_cast<Cch077Doc*>(m_pDocument); }
#endif

