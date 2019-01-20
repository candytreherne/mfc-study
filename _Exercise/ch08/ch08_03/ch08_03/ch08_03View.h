
// ch08_03View.h : interface of the Cch0803View class
//

#pragma once


class Cch0803View : public CView
{
protected: // create from serialization only
	Cch0803View() noexcept;
	DECLARE_DYNCREATE(Cch0803View)

// Attributes
public:
	Cch0803Doc* GetDocument() const;

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
	virtual ~Cch0803View();
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

#ifndef _DEBUG  // debug version in ch08_03View.cpp
inline Cch0803Doc* Cch0803View::GetDocument() const
   { return reinterpret_cast<Cch0803Doc*>(m_pDocument); }
#endif

