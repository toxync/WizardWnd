#pragma once
#include "afxdialogex.h"


// WizardPage1 대화 상자
class WizardPage1 : public CDialogEx
{
	DECLARE_DYNAMIC(WizardPage1)

public:
	WizardPage1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~WizardPage1();
	void GetNumData(int* ap_num1, int* ap_num2);
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
