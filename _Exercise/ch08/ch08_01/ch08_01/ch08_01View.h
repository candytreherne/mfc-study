
// ch08_01View.h : interface of the Cch0801View class
//

#pragma once


class Cch0801View : public CView
{
protected: // create from serialization only
	Cch0801View() noexcept;
	DECLARE_DYNCREATE(Cch0801View)

// Attributes
public:
	Cch0801Doc* GetDocument() const;

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
	virtual ~Cch0801View();
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

#ifndef _DEBUG  // debug version in ch08_01View.cpp
inline Cch0801Doc* Cch0801View::GetDocument() const
   { return reinterpret_cast<Cch0801Doc*>(m_pDocument); }
#endif

