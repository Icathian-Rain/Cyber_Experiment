// LaunchDLL.h : main header file for the LAUNCHDLL DLL
//

#if !defined(AFX_LAUNCHDLL_H__A3C0C3EE_3302_46F9_BEBC_457DD1D53CFC__INCLUDED_)
#define AFX_LAUNCHDLL_H__A3C0C3EE_3302_46F9_BEBC_457DD1D53CFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLaunchDLLApp
// See LaunchDLL.cpp for the implementation of this class
//

#define DllExport __declspec(dllexport)

DllExport void WINAPI InstallLaunchEv();


class CLaunchDLLApp : public CWinApp
{
public:
	CLaunchDLLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLaunchDLLApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CLaunchDLLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};




/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAUNCHDLL_H__A3C0C3EE_3302_46F9_BEBC_457DD1D53CFC__INCLUDED_)
