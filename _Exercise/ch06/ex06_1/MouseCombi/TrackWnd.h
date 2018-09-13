#pragma once
#include <afxwin.h>
class TrackWnd :
	public CWnd
{
public:
	TrackWnd();
	~TrackWnd();

public:
	BOOL m_bTrack;

	DECLARE_MESSAGE_MAP()
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMouseLeave();
};

