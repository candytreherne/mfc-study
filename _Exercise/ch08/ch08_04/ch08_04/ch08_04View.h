
// ch08_04View.h : interface of the Cch0804View class
//

#pragma once


class Cch0804View : public CView
{
protected: // create from serialization only
	Cch0804View() noexcept;
	DECLARE_DYNCREATE(Cch0804View)

// Attributes
public:
	Cch0804Doc* GetDocument() const;

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
	virtual ~Cch0804View();
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

#ifndef _DEBUG  // debug version in ch08_04View.cpp
inline Cch0804Doc* Cch0804View::GetDocument() const
   { return reinterpret_cast<Cch0804Doc*>(m_pDocument); }
#endif

