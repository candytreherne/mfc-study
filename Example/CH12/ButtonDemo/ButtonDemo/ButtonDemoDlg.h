
// ButtonDemoDlg.h : header file
//

#pragma once


// CButtonDemoDlg dialog
class CButtonDemoDlg : public CDialogEx
{
// Construction
public:
	CButtonDemoDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BUTTONDEMO_DIALOG };
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
	afx_msg void OnBnClickedButton1();
	BOOL m_bAuto;
	BOOL m_bUpdate;
	BOOL m_bSystem;
	afx_msg void OnBnClickedCheckAuto();
	int m_nOS;
};
