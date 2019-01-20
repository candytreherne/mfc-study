
// CH08_BmpDisplayDemoDoc.h : interface of the CCH08BmpDisplayDemoDoc class
//


#pragma once


class CCH08BmpDisplayDemoDoc : public CDocument
{
protected: // create from serialization only
	CCH08BmpDisplayDemoDoc() noexcept;
	DECLARE_DYNCREATE(CCH08BmpDisplayDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CCH08BmpDisplayDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
