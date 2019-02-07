
// ListComboDemoDlg.h : header file
//

#pragma once


// CListComboDemoDlg dialog
class CListComboDemoDlg : public CDialogEx
{
// Construction
public:
	CListComboDemoDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTCOMBODEMO_DIALOG };
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
	CListBox m_List;
	CString m_strInput;
	afx_msg void OnBnClickedButtonInsertString();
	afx_msg void OnBnClickedButtonAddString();
	afx_msg void OnBnClickedButtonDelItem();
	afx_msg void OnBnClickedButtonDelAll();
	afx_msg void OnBnClickedButtonFind();
	afx_msg void OnBnClickedButtonFindExact();
	CString m_strSelected;
	afx_msg void OnLbnSelchangeList1();
	CComboBox m_Combo_Address;
	CString m_strAddress;
	afx_msg void OnBnClickedButtonAddAddress();
};
