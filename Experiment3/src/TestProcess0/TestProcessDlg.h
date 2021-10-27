// TestProcessDlg.h : header file
//

#if !defined(AFX_TESTPROCESSDLG_H__6674FFDF_6C44_4772_8258_510E0664E1DB__INCLUDED_)
#define AFX_TESTPROCESSDLG_H__6674FFDF_6C44_4772_8258_510E0664E1DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestProcessDlg dialog

class CTestProcessDlg : public CDialog
{
// Construction
public:
	CTestProcessDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestProcessDlg)
	enum { IDD = IDD_TESTPROCESS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestProcessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestProcessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnSelchangeList1();
	afx_msg void OnSelchangeList2();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPROCESSDLG_H__6674FFDF_6C44_4772_8258_510E0664E1DB__INCLUDED_)
