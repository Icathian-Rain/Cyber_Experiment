// TestProcess2Dlg.h : header file
//

#if !defined(AFX_TESTPROCESS2DLG_H__80BE4A2C_43BA_401C_ABDA_26185A78A44B__INCLUDED_)
#define AFX_TESTPROCESS2DLG_H__80BE4A2C_43BA_401C_ABDA_26185A78A44B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestProcess2Dlg dialog

class CTestProcess2Dlg : public CDialog
{
// Construction
public:
	CTestProcess2Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestProcess2Dlg)
	enum { IDD = IDD_TESTPROCESS2_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestProcess2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestProcess2Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTPROCESS2DLG_H__80BE4A2C_43BA_401C_ABDA_26185A78A44B__INCLUDED_)
