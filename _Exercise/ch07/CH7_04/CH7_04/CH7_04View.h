
// CH7_04View.h : interface of the CCH704View class
//

#pragma once


class CCH704View : public CView
{
protected: // create from serialization only
	CCH704View() noexcept;
	DECLARE_DYNCREATE(CCH704View)

// Attributes
public:
	CCH704Doc* GetDocument() const;

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
	virtual ~CCH704View();
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

#ifndef _DEBUG  // debug version in CH7_04View.cpp
inline CCH704Doc* CCH704View::GetDocument() const
   { return reinterpret_cast<CCH704Doc*>(m_pDocument); }
#endif

