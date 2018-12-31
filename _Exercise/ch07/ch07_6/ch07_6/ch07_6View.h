
// ch07_6View.h : interface of the Cch076View class
//

#pragma once


class Cch076View : public CView
{
protected: // create from serialization only
	Cch076View() noexcept;
	DECLARE_DYNCREATE(Cch076View)

// Attributes
public:
	Cch076Doc* GetDocument() const;

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
	virtual ~Cch076View();
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

#ifndef _DEBUG  // debug version in ch07_6View.cpp
inline Cch076Doc* Cch076View::GetDocument() const
   { return reinterpret_cast<Cch076Doc*>(m_pDocument); }
#endif

