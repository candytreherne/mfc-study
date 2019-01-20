
// CH08_ImgOutDemoView.h : interface of the CCH08ImgOutDemoView class
//

#pragma once


class CCH08ImgOutDemoView : public CView
{
protected: // create from serialization only
	CCH08ImgOutDemoView() noexcept;
	DECLARE_DYNCREATE(CCH08ImgOutDemoView)

// Attributes
public:
	CCH08ImgOutDemoDoc* GetDocument() const;

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
	virtual ~CCH08ImgOutDemoView();
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

#ifndef _DEBUG  // debug version in CH08_ImgOutDemoView.cpp
inline CCH08ImgOutDemoDoc* CCH08ImgOutDemoView::GetDocument() const
   { return reinterpret_cast<CCH08ImgOutDemoDoc*>(m_pDocument); }
#endif

