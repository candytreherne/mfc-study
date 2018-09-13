#include "stdafx.h"
#include "TrackWnd.h"


TrackWnd::TrackWnd()
{
	m_bTrack = FALSE;
}


TrackWnd::~TrackWnd()
{
}
BEGIN_MESSAGE_MAP(TrackWnd, CWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()


void TrackWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (m_bTrack == FALSE)
	{
		TRACKMOUSEEVENT MouseEvent;
		::ZeroMemory(&MouseEvent, sizeof(MouseEvent));

		MouseEvent.cbSize = sizeof(MouseEvent);
		MouseEvent.dwFlags = TME_LEAVE;
		MouseEvent.hwndTrack = m_hWnd;
		MouseEvent.dwHoverTime = 0;

		m_bTrack = ::_TrackMouseEvent(&MouseEvent);

		if (m_bTrack)
		{
			SetWindowText(TEXT("Tracking..."));
		}
	}

	CWnd::OnMouseMove(nFlags, point);
}


void TrackWnd::OnMouseLeave()
{
	// TODO: Add your message handler code here and/or call default
	TRACKMOUSEEVENT MouseEvent;
	::ZeroMemory(&MouseEvent, sizeof(MouseEvent));

	MouseEvent.cbSize = sizeof(MouseEvent);
	MouseEvent.dwFlags = TME_CANCEL;
	MouseEvent.hwndTrack = m_hWnd;

	::_TrackMouseEvent(&MouseEvent);

	m_bTrack = FALSE;
	SetWindowText(TEXT("WM_MOUSELEAVE"));

	CWnd::OnMouseLeave();
}
