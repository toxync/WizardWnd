#pragma once
#include "afxdialogex.h"


// WizardPage3 대화 상자
class WizardPage3 : public CDialogEx
{
	DECLARE_DYNAMIC(WizardPage3)

public:
	WizardPage3(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~WizardPage3();
	void SetResultValue(int a_result);
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
