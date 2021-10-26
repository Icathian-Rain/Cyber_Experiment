// KeyHookView.cpp : implementation of the CKeyHookView class
//

#include "stdafx.h"
#include "KeyHook.h"
#include "LaunchDLL.h"
#include "KeyHookDoc.h"
#include "KeyHookView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CKeyHookView

IMPLEMENT_DYNCREATE(CKeyHookView, CView)

BEGIN_MESSAGE_MAP(CKeyHookView, CView)
	//{{AFX_MSG_MAP(CKeyHookView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CKeyHookView construction/destruction

CKeyHookView::CKeyHookView()
{
	// TODO: add construction code here

}

CKeyHookView::~CKeyHookView()
{
}




BOOL CKeyHookView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CKeyHookView drawing

void CKeyHookView::OnDraw(CDC* pDC)
{
	CKeyHookDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CKeyHookView printing

BOOL CKeyHookView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CKeyHookView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CKeyHookView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CKeyHookView diagnostics

#ifdef _DEBUG
void CKeyHookView::AssertValid() const
{
	CView::AssertValid();
}

void CKeyHookView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKeyHookDoc* CKeyHookView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKeyHookDoc)));
	return (CKeyHookDoc*)m_pDocument;
}


/////////////////////////////////////////////////////////////////////////////
// CKeyHookView message handlers

void CKeyHookView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	InstallLaunchEv();
}


#endif //_DEBUG