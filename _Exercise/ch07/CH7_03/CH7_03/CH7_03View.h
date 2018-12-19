
// CH7_03View.h : interface of the CCH703View class
//

#pragma once


class CCH703View : public CView
{
protected: // create from serialization only
	CCH703View() noexcept;
	DECLARE_DYNCREATE(CCH703View)

// Attributes
public:
	CCH703Doc* GetDocument() const;

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
	virtual ~CCH703View();
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

#ifndef _DEBUG  // debug version in CH7_03View.cpp
inline CCH703Doc* CCH703View::GetDocument() const
   { return reinterpret_cast<CCH703Doc*>(m_pDocument); }
#endif

