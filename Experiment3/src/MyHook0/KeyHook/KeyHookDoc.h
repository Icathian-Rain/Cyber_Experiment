// KeyHookDoc.h : interface of the CKeyHookDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KEYHOOKDOC_H__D0D0A174_56FA_424E_A201_267EF1D381C5__INCLUDED_)
#define AFX_KEYHOOKDOC_H__D0D0A174_56FA_424E_A201_267EF1D381C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKeyHookDoc : public CDocument
{
protected: // create from serialization only
	CKeyHookDoc();
	DECLARE_DYNCREATE(CKeyHookDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyHookDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CKeyHookDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKeyHookDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYHOOKDOC_H__D0D0A174_56FA_424E_A201_267EF1D381C5__INCLUDED_)
