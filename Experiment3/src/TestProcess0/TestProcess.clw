; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTestProcessDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TestProcess.h"

ClassCount=4
Class1=CTestProcessApp
Class2=CTestProcessDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TESTPROCESS_DIALOG

[CLS:CTestProcessApp]
Type=0
HeaderFile=TestProcess.h
ImplementationFile=TestProcess.cpp
Filter=N

[CLS:CTestProcessDlg]
Type=0
HeaderFile=TestProcessDlg.h
ImplementationFile=TestProcessDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=TestProcessDlg.h
ImplementationFile=TestProcessDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TESTPROCESS_DIALOG]
Type=1
Class=CTestProcessDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_LIST1,listbox,1352728835
Control6=IDC_LIST2,listbox,1352728835

