
// CH08_BmpDisplayDemoDoc.cpp : implementation of the CCH08BmpDisplayDemoDoc class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "CH08_BmpDisplayDemo.h"
#endif

#include "CH08_BmpDisplayDemoDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CCH08BmpDisplayDemoDoc

IMPLEMENT_DYNCREATE(CCH08BmpDisplayDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CCH08BmpDisplayDemoDoc, CDocument)
END_MESSAGE_MAP()


// CCH08BmpDisplayDemoDoc construction/destruction

CCH08BmpDisplayDemoDoc::CCH08BmpDisplayDemoDoc() noexcept
{
	// TODO: add one-time construction code here

}

CCH08BmpDisplayDemoDoc::~CCH08BmpDisplayDemoDoc()
{
}

BOOL CCH08BmpDisplayDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CCH08BmpDisplayDemoDoc serialization

void CCH08BmpDisplayDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CCH08BmpDisplayDemoDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CCH08BmpDisplayDemoDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CCH08BmpDisplayDemoDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CCH08BmpDisplayDemoDoc diagnostics

#ifdef _DEBUG
void CCH08BmpDisplayDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCH08BmpDisplayDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCH08BmpDisplayDemoDoc commands
