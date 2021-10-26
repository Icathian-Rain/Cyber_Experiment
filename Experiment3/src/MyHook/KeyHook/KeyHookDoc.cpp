// KeyHookDoc.cpp : implementation of the CKeyHookDoc class
//

#include "stdafx.h"
#include "KeyHook.h"

#include "KeyHookDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKeyHookDoc

IMPLEMENT_DYNCREATE(CKeyHookDoc, CDocument)

BEGIN_MESSAGE_MAP(CKeyHookDoc, CDocument)
	//{{AFX_MSG_MAP(CKeyHookDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyHookDoc construction/destruction

CKeyHookDoc::CKeyHookDoc()
{
	// TODO: add one-time construction code here

}

CKeyHookDoc::~CKeyHookDoc()
{
}

BOOL CKeyHookDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CKeyHookDoc serialization

void CKeyHookDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CKeyHookDoc diagnostics

#ifdef _DEBUG
void CKeyHookDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CKeyHookDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CKeyHookDoc commands
