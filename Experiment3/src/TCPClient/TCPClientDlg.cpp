// TCPClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TCPClient.h"
#include "TCPClientDlg.h"
#include<stdio.h>
#include<string.h>
#include <time.h>
#include "Windows.h"
#include "winsock.h"
#pragma comment(lib, "Ws2_32.lib")




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
// CTCPClientDlg dialog

CTCPClientDlg::CTCPClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTCPClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTCPClientDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTCPClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTCPClientDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTCPClientDlg, CDialog)
	//{{AFX_MSG_MAP(CTCPClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTCPClientDlg message handlers

BOOL CTCPClientDlg::OnInitDialog()
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

void CTCPClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTCPClientDlg::OnPaint() 
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
HCURSOR CTCPClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void getdata(char *buffer)
{
	CTime tm=CTime::GetCurrentTime();
	CString name;
	name.Format("c:\\test\\Key_%d_%d.log",tm.GetMonth(),tm.GetDay());
	FILE* fp;
	fp = fopen(name,"r");
	fgets(buffer,255,fp);
}



void CTCPClientDlg::OnOK() 
{
	// TODO: Add extra validation here
	//CDialog::OnOK();
	int MY_PORT=1036;
	WSADATA wsaData;
	SOCKET conn_sock;
	struct sockaddr_in remote_addr;
	char buffer[255];
	unsigned long bytes_recvd = 0;
	WSAStartup(MAKEWORD(1,1),&wsaData);
	conn_sock = socket(AF_INET, SOCK_STREAM, 0);
	remote_addr.sin_family = AF_INET;
	remote_addr.sin_port = htons(MY_PORT);
	remote_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	getdata(buffer);
	if (connect(conn_sock, (struct sockaddr*)&remote_addr, sizeof(struct sockaddr)) == SOCKET_ERROR) {
		/*MessageBox(_T("Connect Error!"));*/
		MessageBox("Connect Error!");
		return;
	}
	//buffer[0] = 0;
	//buffer[1099] = 0;
	int len = strlen(buffer);
	bytes_recvd = send(conn_sock, buffer, len, 0);
	if (bytes_recvd > 0) {
		MessageBox(("·¢ËÍ³É¹¦!"), 0, 0 );
	}
	buffer[0] = 0;
	recv(conn_sock, buffer, 30, 0);
}
