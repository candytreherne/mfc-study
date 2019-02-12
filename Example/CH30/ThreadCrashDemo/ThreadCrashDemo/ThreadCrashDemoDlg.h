
// ThreadCrashDemoDlg.h : header file
//

#pragma once


// CThreadCrashDemoDlg dialog
class CThreadCrashDemoDlg : public CDialogEx
{
// Construction
public:
	CThreadCrashDemoDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THREADCRASHDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonBeginThread1();
	afx_msg void OnBnClickedButtonBeginThread2();
	afx_msg void OnBnClickedButtonCallGetstring();
};
