
// CH7_02View.h : interface of the CCH702View class
//

#pragma once


class CCH702View : public CView
{
protected: // create from serialization only
	CCH702View() noexcept;
	DECLARE_DYNCREATE(CCH702View)

// Attributes
public:
	CCH702Doc* GetDocument() const;

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
	virtual ~CCH702View();
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

#ifndef _DEBUG  // debug version in CH7_02View.cpp
inline CCH702Doc* CCH702View::GetDocument() const
   { return reinterpret_cast<CCH702Doc*>(m_pDocument); }
#endif

