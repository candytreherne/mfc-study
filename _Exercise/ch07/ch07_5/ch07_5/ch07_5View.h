
// ch07_5View.h : interface of the Cch075View class
//

#pragma once


class Cch075View : public CView
{
protected: // create from serialization only
	Cch075View() noexcept;
	DECLARE_DYNCREATE(Cch075View)

// Attributes
public:
	Cch075Doc* GetDocument() const;

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
	virtual ~Cch075View();
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

#ifndef _DEBUG  // debug version in ch07_5View.cpp
inline Cch075Doc* Cch075View::GetDocument() const
   { return reinterpret_cast<Cch075Doc*>(m_pDocument); }
#endif

