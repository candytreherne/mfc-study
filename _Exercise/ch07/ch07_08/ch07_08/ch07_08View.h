
// ch07_08View.h : interface of the Cch0708View class
//

#pragma once


class Cch0708View : public CView
{
protected: // create from serialization only
	Cch0708View() noexcept;
	DECLARE_DYNCREATE(Cch0708View)

// Attributes
public:
	Cch0708Doc* GetDocument() const;

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
	virtual ~Cch0708View();
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
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	bool isLButtonDown;
	CPoint start_pt;
	CPoint end_pt;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in ch07_08View.cpp
inline Cch0708Doc* Cch0708View::GetDocument() const
   { return reinterpret_cast<Cch0708Doc*>(m_pDocument); }
#endif

