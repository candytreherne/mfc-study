
// ch08_02View.h : interface of the Cch0802View class
//

#pragma once


class Cch0802View : public CView
{
protected: // create from serialization only
	Cch0802View() noexcept;
	DECLARE_DYNCREATE(Cch0802View)

// Attributes
public:
	Cch0802Doc* GetDocument() const;

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
	virtual ~Cch0802View();
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

#ifndef _DEBUG  // debug version in ch08_02View.cpp
inline Cch0802Doc* Cch0802View::GetDocument() const
   { return reinterpret_cast<Cch0802Doc*>(m_pDocument); }
#endif

