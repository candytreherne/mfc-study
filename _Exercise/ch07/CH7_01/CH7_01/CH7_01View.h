
// CH7_01View.h : interface of the CCH701View class
//

#pragma once


class CCH701View : public CView
{
protected: // create from serialization only
	CCH701View() noexcept;
	DECLARE_DYNCREATE(CCH701View)

// Attributes
public:
	CCH701Doc* GetDocument() const;

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
	virtual ~CCH701View();
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

#ifndef _DEBUG  // debug version in CH7_01View.cpp
inline CCH701Doc* CCH701View::GetDocument() const
   { return reinterpret_cast<CCH701Doc*>(m_pDocument); }
#endif

