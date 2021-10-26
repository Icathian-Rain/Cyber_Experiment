// TCPClientDlg.h : header file
//

#if !defined(AFX_TCPCLIENTDLG_H__1065FA26_CD77_46EB_A771_F814A48A9E5B__INCLUDED_)
#define AFX_TCPCLIENTDLG_H__1065FA26_CD77_46EB_A771_F814A48A9E5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTCPClientDlg dialog

class CTCPClientDlg : public CDialog
{
// Construction
public:
	CTCPClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTCPClientDlg)
	enum { IDD = IDD_TCPCLIENT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTCPClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPCLIENTDLG_H__1065FA26_CD77_46EB_A771_F814A48A9E5B__INCLUDED_)
