; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTCPClientDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "TCPClient.h"

ClassCount=4
Class1=CTCPClientApp
Class2=CTCPClientDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_TCPCLIENT_DIALOG

[CLS:CTCPClientApp]
Type=0
HeaderFile=TCPClient.h
ImplementationFile=TCPClient.cpp
Filter=N

[CLS:CTCPClientDlg]
Type=0
HeaderFile=TCPClientDlg.h
ImplementationFile=TCPClientDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=TCPClientDlg.h
ImplementationFile=TCPClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_TCPCLIENT_DIALOG]
Type=1
Class=CTCPClientDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352

