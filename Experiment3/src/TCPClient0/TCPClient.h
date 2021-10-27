// TCPClient.h : main header file for the TCPCLIENT application
//

#if !defined(AFX_TCPCLIENT_H__636546AF_DA18_4EDE_BAC9_EE10FAA83001__INCLUDED_)
#define AFX_TCPCLIENT_H__636546AF_DA18_4EDE_BAC9_EE10FAA83001__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTCPClientApp:
// See TCPClient.cpp for the implementation of this class
//

class CTCPClientApp : public CWinApp
{
public:
	CTCPClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCPClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTCPClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCPCLIENT_H__636546AF_DA18_4EDE_BAC9_EE10FAA83001__INCLUDED_)
