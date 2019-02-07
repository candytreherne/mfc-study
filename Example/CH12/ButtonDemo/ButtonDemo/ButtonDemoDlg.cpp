
// ButtonDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ButtonDemo.h"
#include "ButtonDemoDlg.h"
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


// CButtonDemoDlg dialog



CButtonDemoDlg::CButtonDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_BUTTONDEMO_DIALOG, pParent)
	, m_bAuto(TRUE)
	, m_bUpdate(FALSE)
	, m_bSystem(FALSE)
	, m_nOS(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CButtonDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_AUTO, m_bAuto);
	DDX_Check(pDX, IDC_CHECK_UPDATE, m_bUpdate);
	DDX_Check(pDX, IDC_CHECK_SYSTEM, m_bSystem);
	DDX_Radio(pDX, IDC_RADIO_OS1, m_nOS);
}

BEGIN_MESSAGE_MAP(CButtonDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CButtonDemoDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK_AUTO, &CButtonDemoDlg::OnBnClickedCheckAuto)
END_MESSAGE_MAP()


// CButtonDemoDlg message handlers

BOOL CButtonDemoDlg::OnInitDialog()
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
	GetDlgItem(IDC_CHECK_UPDATE)->EnableWindow(FALSE);
	GetDlgItem(IDC_CHECK_SYSTEM)->EnableWindow(FALSE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CButtonDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CButtonDemoDlg::OnPaint()
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
HCURSOR CButtonDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CButtonDemoDlg::OnBnClickedButton1()
{
	// Example #1
	//AfxMessageBox(TEXT("Test Button을 클릭 하였습니다."));

	// Example #2
	//m_bAuto = FALSE;
	//m_bUpdate = TRUE;
	//m_bSystem = TRUE;

	//UpdateData(FALSE);

	// Example #3
	UpdateData();

	CString strOS;
	switch (m_nOS)
	{
	case 0:
		strOS = TEXT("MacOS");
		break;
	case 1:
		strOS = TEXT("Upbuntu");
		break;
	case 2:
		strOS = TEXT("Windows");
		break;
	default:
		break;
	}

	AfxMessageBox(strOS);
}


void CButtonDemoDlg::OnBnClickedCheckAuto()
{
	UpdateData();

	if (m_bAuto)
	{
		GetDlgItem(IDC_CHECK_UPDATE)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK_SYSTEM)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_CHECK_UPDATE)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECK_SYSTEM)->EnableWindow(TRUE);
	}
}
