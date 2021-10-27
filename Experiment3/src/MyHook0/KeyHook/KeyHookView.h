// KeyHookView.h : interface of the CKeyHookView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KEYHOOKVIEW_H__58F5D15B_B743_4AAB_869A_1A3BD593C4F8__INCLUDED_)
#define AFX_KEYHOOKVIEW_H__58F5D15B_B743_4AAB_869A_1A3BD593C4F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKeyHookView : public CView
{
protected: // create from serialization only
	CKeyHookView();
	DECLARE_DYNCREATE(CKeyHookView)

// Attributes
public:
	CKeyHookDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyHookView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void OnInitialUpdate();
	virtual ~CKeyHookView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKeyHookView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in KeyHookView.cpp
inline CKeyHookDoc* CKeyHookView::GetDocument()
   { return (CKeyHookDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYHOOKVIEW_H__58F5D15B_B743_4AAB_869A_1A3BD593C4F8__INCLUDED_)
