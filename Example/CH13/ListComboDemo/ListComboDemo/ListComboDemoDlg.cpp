
// ListComboDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ListComboDemo.h"
#include "ListComboDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CListComboDemoDlg dialog



CListComboDemoDlg::CListComboDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LISTCOMBODEMO_DIALOG, pParent)
	, m_strInput(_T(""))
	, m_strSelected(_T(""))
	, m_strAddress(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CListComboDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Text(pDX, IDC_EDIT_INPUT, m_strInput);
	DDX_Text(pDX, IDC_STATIC_SELECTED_STRING, m_strSelected);
	DDX_Control(pDX, IDC_COMBO_ADDRESS, m_Combo_Address);
	DDX_CBString(pDX, IDC_COMBO_ADDRESS, m_strAddress);
}

BEGIN_MESSAGE_MAP(CListComboDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_INSERT_STRING, &CListComboDemoDlg::OnBnClickedButtonInsertString)
	ON_BN_CLICKED(IDC_BUTTON_ADD_STRING, &CListComboDemoDlg::OnBnClickedButtonAddString)
	ON_BN_CLICKED(IDC_BUTTON_DEL_ITEM, &CListComboDemoDlg::OnBnClickedButtonDelItem)
	ON_BN_CLICKED(IDC_BUTTON_DEL_ALL, &CListComboDemoDlg::OnBnClickedButtonDelAll)
	ON_BN_CLICKED(IDC_BUTTON_FIND, &CListComboDemoDlg::OnBnClickedButtonFind)
	ON_BN_CLICKED(IDC_BUTTON_FIND_EXACT, &CListComboDemoDlg::OnBnClickedButtonFindExact)
	ON_LBN_SELCHANGE(IDC_LIST1, &CListComboDemoDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON_ADD_ADDRESS, &CListComboDemoDlg::OnBnClickedButtonAddAddress)
END_MESSAGE_MAP()


// CListComboDemoDlg message handlers

BOOL CListComboDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	m_Combo_Address.AddString(TEXT("서울"));
	m_Combo_Address.AddString(TEXT("인천"));
	m_Combo_Address.AddString(TEXT("대전"));
	m_Combo_Address.AddString(TEXT("대구"));
	m_Combo_Address.AddString(TEXT("광주"));
	m_Combo_Address.AddString(TEXT("울산"));
	m_Combo_Address.AddString(TEXT("부산"));


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CListComboDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CListComboDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CListComboDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CListComboDemoDlg::OnBnClickedButtonInsertString()
{
	UpdateData();
	
	if (m_strInput == "")
		AfxMessageBox(TEXT("입력값이 없습니다."));
	else
	{
		m_List.InsertString(0, m_strInput);

		m_strInput = TEXT("");
		UpdateData(FALSE);
	}
}


void CListComboDemoDlg::OnBnClickedButtonAddString()
{
	UpdateData();

	if (m_strInput == "")
		AfxMessageBox(TEXT("입력 값이 없습니다."));
	else
	{
		m_List.AddString(m_strInput);

		m_strInput = TEXT("");
		UpdateData(FALSE);
	}

}


void CListComboDemoDlg::OnBnClickedButtonDelItem()
{
	int item = m_List.GetCurSel();
	m_List.DeleteString(item);
}


void CListComboDemoDlg::OnBnClickedButtonDelAll()
{
	m_List.ResetContent();
}


void CListComboDemoDlg::OnBnClickedButtonFind()
{
	UpdateData();

	CString strTemp;
	CString strFind;
	int index = m_List.FindString(-1, m_strInput);

	if (index != LB_ERR)
	{
		m_List.GetText(index, strFind);
		m_List.SetCurSel(index);
		strTemp.Format(TEXT("%d: %s"), index, strFind);
		AfxMessageBox(strTemp);
	}
	else
		AfxMessageBox(TEXT("일치하는 항목을 찾을 수 없습니다."));
}


void CListComboDemoDlg::OnBnClickedButtonFindExact()
{
	UpdateData();

	CString strTemp;
	CString strFind;
	int index = m_List.FindStringExact(-1, m_strInput);

	if (index != LB_ERR)
	{
		m_List.GetText(index, strFind);
		m_List.SetCurSel(index);
		strTemp.Format(TEXT("%d: %s"), index, strFind);
		AfxMessageBox(strTemp);
	}
	else
		AfxMessageBox(TEXT("일치하는 항목을 찾을 수 없습니다."));
}


void CListComboDemoDlg::OnLbnSelchangeList1()
{
	int index = m_List.GetCurSel();

	if (index != LB_ERR)
	{
		m_List.GetText(index, m_strSelected);
		UpdateData(FALSE);
	}
}


void CListComboDemoDlg::OnBnClickedButtonAddAddress()
{
	UpdateData();

	m_Combo_Address.AddString(m_strAddress);
	m_List.AddString(m_strAddress);

	m_Combo_Address.SetEditSel(0, -1);
	m_Combo_Address.Clear();
}
