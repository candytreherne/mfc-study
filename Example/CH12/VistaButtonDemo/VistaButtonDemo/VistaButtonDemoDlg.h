
// VistaButtonDemoDlg.h : header file
//

#pragma once


// CVistaButtonDemoDlg dialog
class CVistaButtonDemoDlg : public CDialogEx
{
// Construction
public:
	CVistaButtonDemoDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VISTABUTTONDEMO_DIALOG };
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
	CSplitButton m_SplitButton;
	afx_msg void OnBnClickedSplitButton();
	CButton m_Command_Button;
	afx_msg void OnBnClickedCommand1();
};
