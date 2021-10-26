// TestProcessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestProcess.h"
#include "TestProcessDlg.h"
#include "Mmsystem.h"
#pragma comment(lib, "Winmm.lib")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestProcessDlg dialog

CTestProcessDlg::CTestProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestProcessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestProcessDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestProcessDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestProcessDlg, CDialog)
	//{{AFX_MSG_MAP(CTestProcessDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_LBN_SELCHANGE(IDC_LIST1, OnSelchangeList1)
	ON_LBN_SELCHANGE(IDC_LIST2, OnSelchangeList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestProcessDlg message handlers

BOOL CTestProcessDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestProcessDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestProcessDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestProcessDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


int x = 0;
int y = 0;
int LastTime1 = 0;
int LastTime2 = 0;
int NeedClose = 0;
char Buf[256];
	ULONG WINAPI Thread1(void* pParam) 
{
	CTestProcessDlg* p = (CTestProcessDlg*)pParam;
	CListBox* pList1;
	pList1 = (CListBox*)p->GetDlgItem(IDC_LIST1);
	sprintf(Buf,"Thread1 Start...");
	pList1->AddString((Buf));
	for (;;) {
		x++;
		x = x % 100;
		int t = timeGetTime();
		if ((t - LastTime1) > 1000) {
			sprintf(Buf, "x=%d",x);
			pList1->AddString(Buf);
			LastTime1 = t;
		}
		if (NeedClose) break;
	}
	return 1;
}

ULONG WINAPI Thread2(void* pParam)
{
	CTestProcessDlg* p = (CTestProcessDlg*)pParam;
	CListBox* pList2;
	pList2 = (CListBox*)p->GetDlgItem(IDC_LIST2);
	/*sprintf(Buf, _T("Thread1 Start..."));*/
	pList2->AddString("Thread2 start...");
	CListBox* pList1;
	pList1 = (CListBox*)p->GetDlgItem(IDC_LIST1);
	for (;;) {
		y++;
		y = y % 100;
		char Buf[256];
		int t = timeGetTime();
		if ((t - LastTime2) > 1000) {
			int z = x + y;
			Sleep(0);
			sprintf(Buf,"x=%d y=%d x+y=%d==%d", x, y, x + y, z);
			pList2->AddString(Buf);
			LastTime2 = t;
		}
		if (NeedClose) break;
	}
	return 1;
}

void CTestProcessDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	DWORD ThreadID;
	CreateThread(0,0,Thread1,this,0,&ThreadID);	
}

void CTestProcessDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	DWORD ThreadID;
	CreateThread(0,0,Thread2,this,0,&ThreadID);
}

void CTestProcessDlg::OnSelchangeList1() 
{
	// TODO: Add your control notification handler code here
	
}

void CTestProcessDlg::OnSelchangeList2() 
{
	// TODO: Add your control notification handler code here
	
}

void CTestProcessDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	// CDialog::OnOK();
	SetWindowText("TestProcess");
	ShowWindow(SW_HIDE);

}
