#pragma once
#include "afxdialogex.h"


// WizardPage2 대화 상자
class WizardPage2 : public CDialogEx
{
	DECLARE_DYNAMIC(WizardPage2)

public:
	WizardPage2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~WizardPage2();
	int GetOpType();
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_OpList;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
